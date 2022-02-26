
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
void swapListElements(list *l, int k)
{
    int length=0, i;
    k--;
    node *firstKthPos, *lastKthPos, *current = l->head;
    while (current != NULL)
    {
        current = current->next;
        length++;
    }
    //printf("%d",length);
    current = l->head;
    for (i = 1; i < length; i++)
    {
        if (i   == k)
            firstKthPos = current;
        else if (i == length - k -1)
            lastKthPos = current;
        current = current->next;
    }
    node* nextFirstKth=firstKthPos->next;
    node* nextLastKth=lastKthPos->next;
    node* nextnextLastKth=lastKthPos->next->next;

    firstKthPos->next= nextLastKth;
     nextLastKth->next=nextFirstKth->next;
    lastKthPos->next=nextFirstKth;
    nextFirstKth->next=nextnextLastKth;
  
}

list l;
int main()
{
    int n, i, d, k;
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &d);
        append(&l, d);
    }
    swapListElements(&l, k);
    print(l);
}



