#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    struct node *head;
} list;

typedef struct node
{
    int val;
    struct node *next;
} node;

void print(list l)
{
    node *first = l.head;
    while (first != NULL)
    { 
        printf("%d ", first->val);
        first = first->next;
    }
}
void append(list *l, int k)
{
    node *NewEl = (node *)malloc(sizeof(node));
    NewEl->next = NULL;
    NewEl->val = k;
    if (l->head == NULL)
    {
        l->head = NewEl;
    }
    else
    {
        node *l_foot = l->head;
        while (l_foot->next != NULL)
            l_foot = l_foot->next;
        l_foot->next = NewEl;
    }
}

void removeDuplicates(list *l){
    node *i= l->head, *j = l->head;
    while (i->next != NULL)
    {
        j= i;
        while(j->next !=NULL){
            if (i->val == j->next->val)
            {
                node *nextEl = j->next;
                j->next = nextEl->next;
                free(nextEl);
            }
            j = j->next;
        }
        i = i->next;
    }
}

list l;
int main()
{
    int n,i,d,u;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d",&d);
        append(&l, d);

    }
    removeDuplicates(&l);
    print(l);
}