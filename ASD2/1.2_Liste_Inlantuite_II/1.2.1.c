#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Product
{
    int n, code, quantity;
    float price;
    char name[50], recDate[50], expDate[50];
} Product;

Product createProduct(int code, char *name, float price, int quantity, char *recDate, char *expDate)
{
    //Product *prod_addr=  (Product *)malloc(sizeof(Product));
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
    if(l->head==NULL){
    newElement->next=NULL;
    l->head= newElement;
        return;
    }
    // printf("#3 flag\n");
    
    while (current->next != NULL && p.price > current->next->val.price)
    {
        current = current->next;
    }
    if(current!=l->head || (current!=l->head && current->val.price < newElement->val.price)){
    Node *nextElt= current->next;
    current->next= newElement;
    newElement->next= nextElt;
    }else{
        if(current == NULL){
        newElement->next= NULL;
        l->head= newElement;
        }
        else{
        newElement->next= current;
        l->head= newElement;
        }
    }
    }

Node *findByCode(List l, int code)
{
}
void printValid(List l, char *expDate)
{
}
void printExpired(List l, char *expDate)
{
}
void deleteExpired(List *l, char *expDate)
{
}
void deleteByCode(List *l, int code)
{
}

// int main(){
//     return 1;
// }