#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct list
{
    struct node* head;
} list;

typedef struct node
{
    int val;
    struct node* next;
} node;

void print(list l)
{
    node* first = l.head;
    while (first != NULL)
    {
        printf("%d", first->val);
        first = first->next;
    }
}
void append(list* l, int k)
{
    node* NewEl = (node*)malloc(sizeof(node));
    NewEl->next = NULL;
    NewEl->val = k;
    if (l->head == NULL)
    {
        l->head = NewEl;
    }
    else
    {
        node* l_foot = l->head;
        while (l_foot->next != NULL)
            l_foot = l_foot->next;
        l_foot->next = NewEl;
    }
}

void sum(list* sum, list* l1, list* l2)
{

    node* L1Node = l1->head;
    node* L2Node = l2->head;
    int carry = 0;
    while (L1Node != NULL && L2Node != NULL)
    {
        int sumCif = L1Node->val + L2Node->val;
        if (carry == 1) {
            carry = 0;
            sumCif++;
        }
        if (sumCif > 9) {
            sumCif -= 10;
            carry = 1;
        }
        append(sum, sumCif);
        L1Node = L1Node->next;
        L2Node = L2Node->next;
    }
    while (L1Node != NULL)
    {
        int sumCif = L1Node->val;
        if (carry == 1) {
            carry = 0;
            sumCif++;
        }
        if (sumCif > 9) {
            sumCif -= 10;
            carry = 1;
        }
        append(sum, L1Node->val);
        L1Node = L1Node->next;
    }
    while (L2Node != NULL)
    {
        int sumCif = L2Node->val;
        if (carry == 1) {
            carry = 0;
            sumCif++;
        }
        if (sumCif > 9) {
            sumCif -= 10;
            carry = 1;
        }
        append(sum, L2Node->val);
        L2Node = L2Node->next;
    }
}

void reverseLinkedList(list* l)
{
    node* head = l->head;
    node* prev, * next, * curent = l->head;
    prev = NULL;
    while (curent != NULL)
    {
        next = curent->next;
        curent->next = prev;
        prev = curent;
        curent = next;
    }
    l->head = prev;
}

list l1, l2, l3;
int charToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return 0;
}

int main()
{
    char a, b;
    do {
        scanf("%c", &a);
        if (a >= '0' && a <= '9')
            append(&l1, charToInt(a) % 10);
    } while (a != '\n');
    do
    {
        scanf("%c", &b);
        if (b >= '0' && b <= '9')
            append(&l2, charToInt(b) % 10);
    } while (b != '\n' && b != ' ' && b != 0);
    reverseLinkedList(&l1);
    reverseLinkedList(&l2);

    sum(&l3, &l1, &l2);
    // print(l3);
    reverseLinkedList(&l3);
    print(l3);
}