#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct node {
    int key;
    struct node* left, * right, * parent;
} node;
typedef struct tree {
    node* root;

} tree;
tree a;

void insert(tree* t, int val) {
    node* y = NULL;
    node* x = t->root;
    node* z = malloc(sizeof(node));
    z->key = val;
    z->left = NULL;
    z->right = NULL;
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        t->root = z;
    else if (z->key < y->key)y->left = z;
    else y->right = z;
}

node* search_rec(node* n, int value) {
    if (n == NULL || value == n->key)
        return n;
    if (value < n->key)
        return search_rec(n->left,value);
    else return search_rec(n->right, value);

}
node* search(tree a, int value) {

    return search_rec(a.root,value);

}

tree a;
int main() {

    int i = 0, x;
    node* y;
    node* z;
    while (i < 7) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    y = search(a, 18);
    if (y != NULL)
        printf("Node 18 exists\n");
    else
        printf("Node 18 should be in the Tree\n");

    z = search(a, 5);
    if (z == NULL)
        printf("Node 5 is not present in the Tree\n");
    else
        printf("Node 5 should not be in the Tree\n");
}