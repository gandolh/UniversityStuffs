#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Product
{
    int n, code, quantity;
    float price;
    char name[50], recDate[50], expDate[50];
} Product;

typedef struct Date
{
    char year[50], month[50], day[50];
} Date;

Product createProduct(int code, char *name, float price, int quantity, char *recDate, char *expDate)
{
    // Product *prod_addr=  (Product *)malloc(sizeof(Product));
    Product product;
    product.code = code;
    strcpy(product.name, name);
    product.price = price;
    product.quantity = quantity;
    strcpy(product.recDate, recDate);
    strcpy(product.expDate, expDate);
    return product;
}

typedef struct Node
{
    Product val;
    struct Node *next;
} Node;

typedef struct List
{
    struct Node *head;
} List;
void print(List l)
{
    Node *first = l.head;
    while (first != NULL)
    {
        printf("%d %s %.1f %d %s %s\n", first->val.code, first->val.name, first->val.price, first->val.quantity, first->val.recDate, first->val.expDate);
        first = first->next;
    }
}

void appendSorted(List *l, Product p)
{
    Node *current = l->head;
    Node *newElement = (Node *)malloc(sizeof(Node));
    newElement->val = p;
    if (l->head == NULL)
    {
        newElement->next = NULL;
        l->head = newElement;
        return;
    }
    // printf("#3 flag\n");

    while (current->next != NULL && p.price > current->next->val.price)
    {
        current = current->next;
    }
    if (current != l->head || (current == l->head && current->val.price < newElement->val.price))
    {
        Node *nextElt = current->next;
        current->next = newElement;
        newElement->next = nextElt;
    }
    else
    {
        if (current == NULL)
        {
            newElement->next = NULL;
            l->head = newElement;
        }
        else
        {
            newElement->next = current;
            l->head = newElement;
        }
    }
}

Node *findByCode(List l, int code)
{
    Node *first = l.head;
    while (first != NULL)
    {
        if (first->val.code == code)
            return first;
        first = first->next;
    }
    return NULL;
}

void slice_str(const char *str, char *buffer, int start, int end)
{
    int j = 0;
    for (int i = start; i <= end; ++i)
    {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}

int compareDates(char *date1, char *date2)
{
    /*
    -1 : date1 < date2
    0 : date1 == date2
    1 : date1 >  date2
    */
    Date d1, d2;
    slice_str(date1, d1.year, 6, 9);
    slice_str(date1, d1.month, 3, 4);
    slice_str(date1, &d1.day, 0, 1);
    slice_str(date2, d2.year, 6, 9);
    slice_str(date2, d2.month, 3, 4);
    slice_str(date2, &d2.day, 0, 1);
    // printf("%s %s %s",d1.day,d1.month,d1.year);
    if (strcmp(d1.year, d2.year) < 0)
        return -1;

    else if (strcmp(d1.year, d2.year) > 0)
        return 1;

    if (strcmp(d1.year, d2.year) == 0)
    {
        if (strcmp(d1.month, d2.month) < 0)
            return -1;
        else if (strcmp(d1.month, d2.month) > 0)
            return 1;
        else if (strcmp(d1.day, d2.day) < 0)
            return -1;
        else if (strcmp(d1.day, d2.day) > 0)
            return 1;
        else
            return 0;
    }
}

void printValid(List l, char *expDate)
{
    Node *first = l.head;
    while (first != NULL)
    {
        if (compareDates(expDate, first->val.expDate) < 0)
            printf("%d %s %.1f %d %s %s\n", first->val.code, first->val.name, first->val.price, first->val.quantity, first->val.recDate, first->val.expDate);
        first = first->next;
    }
}

void printExpired(List l, char *expDate)
{
    Node *first = l.head;
    while (first != NULL)
    {
        if (compareDates(expDate, first->val.expDate) > 0)
            printf("%d %s %.1f %d %s %s\n", first->val.code, first->val.name, first->val.price, first->val.quantity, first->val.recDate, first->val.expDate);
        first = first->next;
    }
}
void deleteExpired(List *l, char *expDate)
{
    Node *current = l->head;
    while (current->next != NULL)
    {
        while (compareDates(expDate, current->next->val.expDate) > 0 && current != NULL)
        {
            Node *nextEl = current->next;
            current->next = nextEl->next;
            free(nextEl);
        }
        current = current->next;
    }
    if (compareDates(expDate, l->head->val.expDate) > 0)
    {
        l->head = l->head->next;
    }
}
void deleteByCode(List *l, int code)
{
    Node *current = l->head;
    int found = 0;
    if (l->head->val.code == code)
    {
        Node *elt = l->head;
        l->head = elt->next;
        free(elt);
        found=0;
    }
    while (current->next != NULL && found == 0)
    {
        if (current->next->val.code == code)
        {
            Node *Ukraine = current->next;
            current->next = Ukraine->next;
            found = 1;
            free(Ukraine);
        }
        current = current->next;
    }
}

// int main(){
//     return 1;
// }