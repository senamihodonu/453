#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deq.h"

//0///////////////////////////////////////////////////////
/*Testing the deq_head_put(Deq q, Data d) 
function with 1 element(s) to the list
from the head direction*/
double test0_deq_head_put_1_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("0 - Testing deq_head_put(Deq q, Data d)\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");
  char expected[] = "1";
  q = deq_new();
  
  //List before adding 1 element
  char *s=deq_str(q,0);
  printf("list before operation --> [ %s ]\n",s);
  free(s);

  //adding 1 element to list
  deq_head_put(q, "1");
  char *result=deq_str(q,0);
  printf("list after operation --> [ %s ]\n",result);

  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    free(result);
    deq_del(q,0);
    return 1;
  } else{
    printf("Fail!\n");
    free(result);
    deq_del(q,0);
    return 0;
  }
}
//1///////////////////////////////////////////////////////
/*Testing the deq_head_put(Deq q, Data d) 
function by adding 2 elements to the list
from the head direction*/
double test1_deq_head_put_2_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("1 - Testing deq_head_put(Deq q, Data d) \n");
  printf("w/ 2 element\n");
  printf("----------------------------------\n");
  char expected[] = "2 1";
  q = deq_new();
  //List before adding 2 element
  char *s=deq_str(q,0);
  printf("before operation --> [ %s ]\n",s);
  free(s);

  //adding 2 elements to list
  deq_head_put(q, "1");
  char *r1=deq_str(q,0);
  printf("after first insert --> [ %s ]\n",r1);
  deq_head_put(q, "2");
  char *r2=deq_str(q,0);
  printf("after second insert --> [ %s ]\n",r2);

  //comparing the expected with the result
  if(strcmp(r2,expected)==0){
    fprintf(stderr, "Pass!\n");
    free(r1);
    free(r2);
    deq_del(q,0);
    return 1;
  } else{
    fprintf(stderr, "Fail!\n");
    free(r1);
    free(r2);
    deq_del(q,0);
    return 0;
  }
}

//2///////////////////////////////////////////////////////
/*Testing the deq_tail_put(Deq q, Data d) 
function by adding 1 element(s) to the list 
from the tail direction*/
double test2_deq_tail_put_1_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("2 - Testing deq_tail_put(Deq q, Data d) \n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");
  char expected[] = "1";
  q = deq_new();
  
  //List before adding 2 element
  char *s=deq_str(q,0);
  printf("before operation --> [ %s ]\n",s);
  free(s);

  //adding 1 element to the list
  deq_tail_put(q, "1");
  char *result=deq_str(q,0);
  printf("list after operation --> [ %s ]\n",result);

  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    fprintf(stderr, "Pass!\n");
    free(result);
    deq_del(q,0);
    return 1;
  } else{
    fprintf(stderr, "Fail!\n");
    free(result);
    deq_del(q,0);
    return 0;
  }
}

//3///////////////////////////////////////////////////////
/*Testing the deq_tail_put(Deq q, Data d) 
function by adding 2 element(s) to the list 
from the tail direction*/
double test3_deq_tail_put_2_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("3 - Testing deq_tail_put(Deq q, Data d) \n");
  printf("w/ 2 element\n");
  printf("----------------------------------\n");
  char expected[] = "1 2";
  q = deq_new();
  
  //List before adding 2 element
  char *s=deq_str(q,0);
  printf("before operation --> [ %s ]\n",s);
  free(s);

  //adding 2 elements to list
  deq_tail_put(q, "1");
  char *r1=deq_str(q,0);
  printf("after first insert --> [ %s ]\n",r1);
  deq_tail_put(q, "2");
  char *r2=deq_str(q,0);
  printf("after second insert --> [ %s ]\n",r2);

  //comparing the expected with the result
  if(strcmp(r2,expected)==0){
    fprintf(stderr, "Pass!\n");
    free(r1);
    free(r2);
    deq_del(q,0);
    return 1;
  } else{
    fprintf(stderr, "Fail!\n");
    free(r1);
    free(r2);
    deq_del(q,0);
    return 0;
  }
}

//4///////////////////////////////////////////////////////
/*Testing the deq_head_ith(Deq q, int i) 
function with 1 element*/
double test4_deq_head_ith_1_elements_0th_term(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("4 - Testing deq_head_ith(Deq q, int i) \n");
  printf("Returning element at index 0\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");
  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding one element to list
  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 0th term from the head direction
  char* result =(char*)deq_head_ith(q, 0);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    fprintf(stderr, "Pass!\n");
    deq_del(q,0);
    return 1;
  } else{
    fprintf(stderr, "Fail!\n");
    deq_del(q,0);
    return 0;
  }
}

//5///////////////////////////////////////////////////////
/*Testing the deq_head_ith(Deq q, int i) 
function with 1 element*/
double test5_deq_head_ith_2_elements_0th_term(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("5 - Testing deq_head_ith(Deq q, int i) \n");
  printf("Returning element at index 0\n");
  printf("w/ 2 element\n");
  printf("----------------------------------\n");
  char expected[] = "2";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding element to list
  deq_head_put(q, "2");
  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 0th term from the head direction
  char* result =(char*)deq_head_ith(q, 0);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    fprintf(stderr, "Pass!\n");
    deq_del(q,0);
    return 1;
  } else{
    fprintf(stderr, "Fail!\n");
    deq_del(q,0);
    return 0;
  }
}

//6///////////////////////////////////////////////////////
/*Testing the deq_head_ith(Deq q, int i) 
function with 2 element*/
double test6_deq_head_ith_2_elements_1st_term(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("6 - Testing deq_head_ith(Deq q, int i) \n");
  printf("Returning element at index 1\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");
  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2");
  
  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 0th term from the head direction
  char* result =(char*)deq_head_ith(q, 1);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);
  deq_del(q,0);

  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//7///////////////////////////////////////////////////////
/*Testing the deq_tail_ith(Deq q, int i) 
function with 2 element*/
double test7_deq_tail_ith_1_elements_0th_term(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("7 - Testing deq_tail_ith(Deq q, int i) \n");
  printf("Returning element at index 1\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");
  char src[20];
  strcpy(src,"");

  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  
  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 0th term from the head direction
  char* result =(char*)deq_tail_ith(q, 0);
  strcat(src, result);

  printf("result = %s\n",src);
  printf("expected = %s\n",expected);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(src,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//8///////////////////////////////////////////////////////
/*Testing the deq_tail_ith(Deq q, int i) 
function with 2 element*/
double test8_deq_tail_ith_2_elements_0th_term(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("8 - Testing deq_tail_ith(Deq q, int i) \n");
  printf("Returning element at index 0\n");
  printf("w/ 2 element\n");
  printf("----------------------------------\n");
  // char src[20];
  // strcpy(src,"");

  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list

  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 0th term from the tail direction
  char* result =(char*)deq_tail_ith(q, 0);
  // strcat(src, result);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//9///////////////////////////////////////////////////////
/*Testing the deq_tail_ith(Deq q, int i) 
function with 2 element*/
double test9_deq_tail_ith_2_elements_1st_term(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("9 - Testing deq_tail_ith(Deq q, int i) \n");
  printf("Returning element at index 1\n");
  printf("w/ 2 element\n");
  printf("----------------------------------\n");

  char expected[] = "2";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list

  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_ith(q, 1);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//10///////////////////////////////////////////////////////
/*Testing the deq_head_get(Deq q) 
function with 1 element*/
double test10_deq_head_get_1_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("10 - deq_head_get(Deq q)  \n");
  printf("Returning front element (head direction)\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");

  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  printf("list --> [ %s ]\n",s);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_get(q);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  char *s1=deq_str(q,0);
  printf("list after operation --> [ %s ]\n",s1);
  free(s1);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//11///////////////////////////////////////////////////////
/*Testing the deq_head_get(Deq q) 
function with 2 element*/
double test11_deq_head_get_2_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("11 - deq_head_get(Deq q)\n");
  printf("Returning front element (head direction)\n");
  printf("w/ 2 element\n");
  printf("----------------------------------\n");

  char expected[] = "2";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_get(q);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//12///////////////////////////////////////////////////////
/*Testing the deq_head_get(Deq q) 
function with 3 element*/
double test12_deq_head_get_3_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("12 - deq_head_get(Deq q)\n");
  printf("Returning front element (head direction)\n");
  printf("w/ 3 element\n");
  printf("----------------------------------\n");

  char expected[] = "3";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list
  deq_head_put(q, "3"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_get(q);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//13///////////////////////////////////////////////////////
/*Testing the deq_tail_get(Deq q) 
function with 1 element*/
double test13_deq_tail_get_1_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("13 - deq_tail_get(Deq q)\n");
  printf("Returning front element (tail direction)\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");

  char expected[] = "1";
  q = deq_new();
  //List before operation
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("before operation --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_get(q);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    deq_del(q,0);
    return 1;
  } else{
    deq_del(q,0);
    printf("Fail!\n");
    return 0;
  }
}

//14///////////////////////////////////////////////////////
/*Testing the deq_tail_get(Deq q) 
function with 1 element*/
double test14_deq_tail_get_2_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("14 - deq_tail_get(Deq q)\n");
  printf("Returning front element (tail direction)\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");

  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_get(q);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//15///////////////////////////////////////////////////////
/*Testing the deq_tail_get(Deq q) 
function with 3 element*/
double test15_deq_tail_get_3_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("15 - deq_tail_get(Deq q)\n");
  printf("Returning front element (tail direction)\n");
  printf("w/ 1 element\n");
  printf("----------------------------------\n");

  char expected[] = "1";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list
  deq_head_put(q, "3"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_get(q);

  printf("result = %s\n",result);
  printf("expected = %s\n",expected);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  //comparing the expected with the result
  if(strcmp(result,expected)==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}


//16///////////////////////////////////////////////////////
/*Testing the deq_head_rem(Deq q, Data d)
function with 3 element*/
double test16_deq_head_rem_at_head(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("16 - deq_head_rem(Deq q, Data d)\n");
  printf("remove term at the head\n");
  printf("----------------------------------\n");

  char expected[] = "[ 3 2 1 ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list
  deq_head_put(q, "3"); //adding elements to list
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_rem(q, "1");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  char* ith = (char*)deq_tail_ith(q, 0);
  deq_del(q,0);
  
  //comparing the expected with the result
  if(strcmp(ith,"1")==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//17///////////////////////////////////////////////////////
/*Testing the deq_head_rem(Deq q, Data d)
function with 3 element*/
double test17_deq_tail_rem_at_tail(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("17 - deq_tail_rem(Deq q, Data d)\n");
  printf("remove term at the tail\n");
  printf("----------------------------------\n");

  char expected[] = "[ 1 3 2 ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list
  deq_head_put(q, "2"); //adding elements to list
  deq_head_put(q, "3"); //adding elements to list
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_rem(q, "1");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  char* ith = (char*)deq_tail_ith(q, 0);
  deq_del(q,0);

  //comparing the expected with the result
  if(strcmp(ith,"2")==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//18///////////////////////////////////////////////////////
/*Testing the deq_head_rem(Deq q, Data d)*/
double test18_deq_head_rem_at_middle(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("18 - deq_head_rem(Deq q, Data d)\n");
  printf("term in the middle\n");
  printf("----------------------------------\n");

  char expected[] = "[ 1 3 6 4 5]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "5"); //adding elements to list
  deq_head_put(q, "4"); //adding elements to list<----
  deq_head_put(q, "6"); //adding elements to list
  deq_head_put(q, "4"); //adding elements to list
  deq_head_put(q, "3"); //adding elements to list
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_rem(q, "4");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  char* ith = (char*)deq_tail_ith(q, 2);
  deq_del(q,0);
  
  //comparing the expected with the result
  if(strcmp(ith,"6")==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//19///////////////////////////////////////////////////////
/*Testing the deq_tail_rem(Deq q, Data d)*/
double test19_deq_tail_rem_at_middle(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("19 - deq_tail_rem(Deq q, Data d)\n");
  printf("term in the middle\n");
  printf("----------------------------------\n");

  char expected[] = "[ 1 3 4 6 5 ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "5"); //adding elements to list
  deq_head_put(q, "4"); //adding elements to list<----<
  deq_head_put(q, "6"); //adding elements to list
  deq_head_put(q, "4"); //adding elements to list
  deq_head_put(q, "3"); //adding elements to list
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_rem(q, "4");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  char* ith = (char*)deq_tail_ith(q, 1);
  deq_del(q,0);
  
  //comparing the expected with the result
  if(strcmp(ith,"6")==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//20///////////////////////////////////////////////////////
/*Testing the deq_head_rem(Deq q, Data d)*/
double test20_deq_head_rem_1_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("20 - deq_head_rem(Deq q, Data d)\n");
  printf("single item in list\n");
  printf("----------------------------------\n");

  char expected[] = "[  ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_rem(q, "1");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  
  //comparing the expected with the result
  if(size1==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//21///////////////////////////////////////////////////////
/*Testing the deq_tail_rem(Deq q, Data d)
function with 3 element*/
double test21_deq_tail_rem_1_elements(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("21 - deq_tail_rem(Deq q, Data d)\n");
  printf("single item in list\n");
  printf("----------------------------------\n");

  char expected[] = "[  ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "1"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_rem(q, "1");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  
  //comparing the expected with the result
  if(size1==0){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}

//22///////////////////////////////////////////////////////
/*Testing the deq_head_rem(Deq q, Data d)*/
double test22_deq_head_rem_1_elements_not_present(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("22 - deq_head_rem(Deq q, Data d)\n");
  printf("item not in list\n");
  printf("----------------------------------\n");

  char expected[] = "[ 2 ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "2"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_head_rem(q, "1");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  
  //comparing the expected with the result
  if(size1==1){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}


//23///////////////////////////////////////////////////////
/*Testing the deq_head_rem(Deq q, Data d)*/
double test23_deq_tail_rem_1_elements_not_present(Deq q) {
  printf("\n///////////////////////////////////////\n");
  printf("23 - deq_head_rem(Deq q, Data d)\n");
  printf("item not in list\n");
  printf("----------------------------------\n");

  char expected[] = "[ 2 ]";
  q = deq_new();

  //List before operation
  deq_head_put(q, "2"); //adding elements to list

  char *s=deq_str(q,0);
  int size = deq_len(q);
  printf("list --> [ %s ], size = %d\n",s, size);
  free(s);

  //first 1st term from the tail direction
  char* result =(char*)deq_tail_rem(q, "1");
  printf("data to remove --> %s\n", result);

  char *s1=deq_str(q,0);
  int size1 = deq_len(q);
  printf("expected --> %s\n",expected);
  printf("list after operation --> [ %s ], size = %d\n",s1, size1);
  free(s1);

  deq_del(q,0);
  
  //comparing the expected with the result
  if(size1==1){
    printf("Pass!\n");
    return 1;
  } else{
    printf("Fail!\n");
    return 0;
  }
}




int main() {
  int i;
  int n = 24;
  double count = 0;
  double test_list[n]; 

  for (i = 0; i < n; i++)
    test_list[i] = 0;

  Deq q=deq_new();

  test_list[0] = test0_deq_head_put_1_elements(q);
  test_list[1] = test1_deq_head_put_2_elements(q);
  test_list[2] = test2_deq_tail_put_1_elements(q); 
  test_list[3] = test3_deq_tail_put_2_elements(q); 
  test_list[4] = test4_deq_head_ith_1_elements_0th_term(q);
  test_list[5] = test5_deq_head_ith_2_elements_0th_term(q);
  test_list[6] = test6_deq_head_ith_2_elements_1st_term(q);
  test_list[7] = test7_deq_tail_ith_1_elements_0th_term(q);
  test_list[8] = test8_deq_tail_ith_2_elements_0th_term(q);
  test_list[9] = test9_deq_tail_ith_2_elements_1st_term(q);
  test_list[10] = test10_deq_head_get_1_elements(q); 
  test_list[11] = test11_deq_head_get_2_elements(q);
  test_list[12] = test12_deq_head_get_3_elements(q); 
  test_list[13] = test13_deq_tail_get_1_elements(q);
  test_list[14] = test14_deq_tail_get_2_elements(q); 
  test_list[15] = test15_deq_tail_get_3_elements(q);
  test_list[16] = test16_deq_head_rem_at_head(q); 
  test_list[17] = test17_deq_tail_rem_at_tail(q);
  test_list[18] = test18_deq_head_rem_at_middle(q); 
  test_list[19] = test19_deq_tail_rem_at_middle(q);
  test_list[20] = test20_deq_head_rem_1_elements(q); 
  test_list[21] = test21_deq_tail_rem_1_elements(q);
  test_list[22] = test22_deq_head_rem_1_elements_not_present(q);
  test_list[23] = test23_deq_tail_rem_1_elements_not_present(q);


  for(i = 0; i < n; i++){
    count = count+test_list[i];
  }

  double p = (count/(double)n)*100;


  printf("----------------------------------\n");
  printf("%f percent success\n", p);
  printf("----------------------------------\n");

  deq_del(q,0);
  return 0;
}
