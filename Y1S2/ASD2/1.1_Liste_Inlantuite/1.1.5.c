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


void merge(list *dest, list *l1 , list *l2){
    node* L1Node = l1->head;
    node* L2Node= l2->head;
    while(L1Node!=NULL && L2Node!=NULL){
        if(L1Node->val < L2Node->val){
            append(dest, L1Node->val);
            L1Node= L1Node->next;
        }else{
            append(dest, L2Node->val);
            L2Node= L2Node->next;
        }
    }
    while(L1Node!=NULL){
        append(dest, L1Node->val);
        L1Node= L1Node->next;
    }
    while(L2Node!=NULL){
        append(dest, L2Node->val);
        L2Node= L2Node->next;
    }
}

list l1, l2, l3;
int main(){
    
    int i = 0, j = 0, x;
    while(i < 5){
        scanf("%d", &x);
        i++;
        append(&l1, x);
    }
    while(j < 7){
        scanf("%d", &x);
        j++;
        append(&l2, x);
    }
    merge(&l3, &l1, &l2);
    print(l3);
}