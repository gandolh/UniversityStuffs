#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node * next;
}node;

typedef struct Queue {
   struct node * top;
   struct node * foot;
} Queue;

Queue create_queue(){
 Queue q;
 q.top=NULL;
 q.foot= NULL;
}

void print(Queue* q){
   node * current = q->top;
   while(current != NULL){
       printf("%d\n", current->val);
       current= current->next;
   }
}
void enqueue(Queue *q, int k){
     node* NewEl=(node*)malloc( sizeof(node));
    NewEl->next=NULL;
    NewEl->val= k;
    if(q->top==NULL){
        q->top=NewEl;
        q->foot=NewEl;
    }else{
        node * l_foot= q->foot;
        l_foot->next = NewEl;
        q->foot= NewEl;
    }
}

void dequeue(Queue *q){
    node *top = q->top;
    q->top = q->top->next;
    free(top);
}
