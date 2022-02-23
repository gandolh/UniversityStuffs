#include <stdio.h>

// nu am gasit un tip de date pentru lista in c asa ca imi fac una

struct List
{
    struct List *next;
    int val;
};
struct List * ListHead=NULL;
struct List * ListFoot=NULL;
void printList()
{
    // while (list != NULL)
    // {
    //     printf("%d", list->val);
    //     list=list->next;
    // }
    printf("%d %d", ListHead->val,ListHead->next->val);
}

void insertFirst(int sum)
{
    // printf("%d",sum);
    struct List *newEl;
    newEl->val = sum;
    newEl->next = NULL;
    if(ListHead == NULL){
        ListHead=newEl;
        ListFoot = ListHead;
    }
    else {
        ListFoot->next=newEl; 
        ListFoot = ListFoot->next;
    } 
}

int main()
{
    int lungime, d, i, sum = 1, c;
    scanf("%d %d", &lungime, &c);
    if (c == 1)
    {
        for (i = 1; i <= lungime; i++)
        {
            scanf("%d", &d);
            sum += (i + 1) - (d == 1 ? 1 : 0);
            insertFirst(sum);
        }
        printList();
    }
    else
    {
        i = 2;
    }

    printf("%d\n", sum);
    return 0;
}
