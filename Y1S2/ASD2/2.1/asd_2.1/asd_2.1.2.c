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