#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)
typedef struct Stack{
    struct node * top;
}Stack;

typedef struct node{
    int val;
    struct node * next;
}node;

Stack create_stack(){
    Stack s;
    s.top=NULL;
    return s;
}
void print(Stack* s){
   node * current = s->top;
   while(current != NULL){
       printf("%d ", current->val);
       current= current->next;
   }
}
void push(Stack *s, int k){
    node* NewEl=(node*)malloc( sizeof(node));
    NewEl->val= k;
    node* current = s->top;
    s->top= NewEl;
    NewEl->next=current;
}

void pop(Stack *s){
    node *top = s->top;
    s->top = s->top->next;
    free(top);
}
int main(){
    Stack s = create_stack();
    int x, i;
    
    scanf("%d", &x);
    while(x>0){
        scanf("%d", &i);
        push(&s, i);
        x--;
    }
    pop(&s);
    pop(&s);
    print(&s);
}