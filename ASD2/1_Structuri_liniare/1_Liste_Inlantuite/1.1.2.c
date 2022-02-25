#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    struct node * head;
}list;

typedef struct node{
    int val;
    struct node * next;
}node;


void print(list l){
   node * first = l.head;
   while(first != NULL){
       printf("%d ", first->val);
       first= first->next;
   }
}