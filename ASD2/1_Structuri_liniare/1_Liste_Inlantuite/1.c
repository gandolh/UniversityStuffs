#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int *next;
} node;
typedef struct list
{
    node *head;
} list;

void print(list l)
{
    node *n = l.head;
    while (n != NULL)
    {
        printf("%d ", n->val);
        n = n->next;
    }
}
void append(list *l, int k)
{
    node *n = l->head;
    printf("%d ", l->head->val);
    if (n != NULL)
    {
        printf("2");
        // node *n = l->head;
        while (n->next != NULL)
        {
            n = n->next;
        }
        node *new;
        new->val = k;
        n->next = &new;
        new->next = NULL;
    }
    else
    {
        node *nou;
        nou->val = k;
        nou->next = NULL;
        l->head = nou;
        // printf("%d ", l->head->val);
    }
}