#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "Command.h"
#include "error.h"

typedef struct {
  char *file;
  char **argv;
  T_redir redir;
} *CommandRep;

#define BIARGS CommandRep r, int *eof, Jobs jobs
#define BINAME(name) bi_##name
#define BIDEFN(name) static void BINAME(name) (BIARGS)
#define BIENTRY(name) {#name,BINAME(name)}

static char *owd=0;
static char *cwd=0;
int status;

static void builtin_args(CommandRep r, int n) {
  char **argv=r->argv;
  for (n++; *argv++; n--);
  if (n)
    ERROR("wrong number of arguments to builtin command"); // warn
}

BIDEFN(exit) {
  builtin_args(r,0);
  *eof=1;
}

BIDEFN(pwd) {
  builtin_args(r,0);
  if (!cwd)
    cwd=getcwd(0,0);
  printf("%s\n",cwd);
}

BIDEFN(cd) {
  builtin_args(r,1);
  if (strcmp(r->argv[1],"-")==0) {
    char *twd=cwd;
    cwd=owd;
    owd=twd;
  } else {
    if (owd) free(owd);
    owd=cwd;
    cwd=strdup(r->argv[1]);
  }
  if (cwd && chdir(cwd))
    ERROR("chdir() failed"); // warn
}

static int builtin(BIARGS) {
  typedef struct {
    char *s;
    void (*f)(BIARGS);
  } Builtin;
  static const Builtin builtins[]={
    BIENTRY(exit),
    BIENTRY(pwd),
    BIENTRY(cd),
    {0,0}
  };
  int i;
  for (i=0; builtins[i].s; i++)
    if (!strcmp(r->file,builtins[i].s)) {
      builtins[i].f(r,eof,jobs);
      return 1;
    }
  return 0;
}

static char **getargs(T_words words) {
  int n=0;
  T_words p=words;
  while (p) {
    p=p->words;
    n++;
  }
  char **argv=(char **)malloc(sizeof(char *)*(n+1));
  if (!argv)
    ERROR("malloc() failed");
  p=words;
  int i=0;
  while (p) {
    argv[i++]=strdup(p->word->s);
    p=p->words;
  }
  argv[i]=0;
  return argv;
}

extern Command newCommand(T_words words, T_redir redir) {
  CommandRep r=(CommandRep)malloc(sizeof(*r));
  if (!r)
    ERROR("malloc() failed");
  r->argv=getargs(words);
  r->file=r->argv[0];
  r->redir=redir;
  return r;
}

static void child(CommandRep r, int fg) {
  int eof=0;
  Jobs jobs=newJobs();
  if (builtin(r,&eof,jobs))
    return;
  ////////////////////////////
  // int save =  dup(0);
  // char *out_file = r->redir->word->s;
  // char *out = r->redir->op;
  // int fd = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);

  // if(out){
  //   close(1);
  //   if(fd<0)
  //     exit(1);
  //   dup2(fd,STDOUT_FILENO);
  //   close(fd);    
  //   dup2(save,STDOUT_FILENO);
  //   close(save);
  // } 
  ///////////////////////////
  execvp(r->argv[0],r->argv);
  ERROR("execvp() failed");
  exit(0);
}

extern void execCommand(Command command, Pipeline pipeline, Jobs jobs,
			int *jobbed, int *eof, int fg) {
  CommandRep r=command;
  T_redir dir = r->redir;
  int save =  dup(STDOUT_FILENO);
  int fdO = 0;
  char *out = NULL;
  char *out_file= NULL;
  out_file=(char*)malloc(sizeof(out_file));

  if(dir->op){
    close(STDOUT_FILENO);
    char *out = dir->op;
    char *out_file = dir->word->s;
    
    // char *in = dir->op;
    // char *in_file = dir->word->s;

    if(out){
      // printf("%s\n",out_file);
      fdO = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
      if(fdO<0)
        exit(1);
      dup(fdO);
      fflush(stdout);
    }

    // if(in){
    //   // printf("%s\n",out_file);
    //   fdO = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    //   if(fdO<0)
    //     exit(1);
    //   dup(fdO);
    //   fflush(stdout);
    // }
    // wait(NULL);
  }


  if (fg && builtin(r,eof,jobs)){
    if(dir->op){
      close(fdO);
      dup2(save,STDOUT_FILENO);
      close(save);
    }
    fflush(stdout);
    free(out);
    free(out_file);
    return;
  }

  if (!*jobbed) {
    *jobbed=1;
    addJobs(jobs,pipeline);
  }

  int pid=fork();
  if (pid==-1)
    ERROR("fork() failed");
     
  if (pid==0){
    child(r,fg);
  // ///////////////////////////
  int save =  dup(STDOUT_FILENO);
  int fd = 0;
  char *out = r->redir->op;
  char *out_file = r->redir->word->s;

  if(out){
    close(1);
    fd = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if(fd<0)
      exit(1);
    dup(fd);
    fflush(stdout);
    close(fd);
    dup2(save,STDOUT_FILENO);
    close(save);
    exit(0);
  } 
  // ///////////////////////////
    return;
  } else wait(NULL);
}

extern void freeCommand(Command command) {
  CommandRep r=command;
  char **argv=r->argv;
  while (*argv)
    free(*argv++);
  free(r->argv);
  free(r);
}

extern void freestateCommand() {
  if (cwd) free(cwd);
  if (owd) free(owd);
}