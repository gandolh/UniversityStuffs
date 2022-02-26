#include<stdio.h>
#include<stdlib.h>
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
void append(list *l, int k){
    node* NewEl=(node*)malloc( sizeof(node));
    NewEl->next=NULL;
    NewEl->val= k;
    if(l->head==NULL){
        l->head=NewEl;
    }else{
        node * l_foot= l->head;
        while(l_foot->next!=NULL)
            l_foot= l_foot->next;
        l_foot->next = NewEl;
    }
}


int findKthFromEnd(int k, list l){
    int length=0,i;
    node* start= l.head;
    while(start){
        start= start->next;
        length++;
    }
    start = l.head;
    for( i=0;i< length-k;i++)start= start->next;
    return start->val;


    return 1;
}

list l;
int main(){
    
    int i = 0,x;
    while(i < 7){
        scanf("%d", &x);
        i++;
        append(&l, x);
    }
    x = findKthFromEnd(3, l);
    printf("%d\n", x);
}


