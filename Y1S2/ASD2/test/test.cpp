
#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
/// <summary>
/// sterge si referinta din arbore cand stergi un nod cu free
/// </summary>
typedef struct node {
    int key;
    struct node* left, * right, * parent;
} node;
typedef struct tree {
    node* root;

} tree;
tree a;


node* search_rec(node* n, int value) {
    if (n == NULL || value == n->key)
        return n;
    if (value < n->key)
        return search_rec(n->left, value);
    else return search_rec(n->right, value);

}
node* search(tree* a, int value) {

    return search_rec(a->root, value);

}



void delete_node(tree* a, int v) {
    node* result = search(a,v);
    if (result->left == NULL && result->right == NULL) {
        free(result);
    }
    else if (result->left != NULL && result->right != NULL) 
    {
        node* initial = result;
        node* prev = result;
        result = result->right;
        while (result->left) {
            prev = result;
            result = result->left;
        }
        initial->key = prev->key;
    }
    else {
        result = result->left ? result->left : result->right;
    }
}

void insert(tree* t, int val) {
    node* y = NULL;
    node* x = t->root;
    node* z = (node*)malloc(sizeof(node));
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


void handlePreorder(node* nod) {
    if (nod) {
        printf("%d ", nod->key);
        handlePreorder(nod->left);
        handlePreorder(nod->right);
    }
}

void preorder(const tree& a) {
    handlePreorder(a.root);
}


int main() {

    int i = 0, x;
    while (i < 9) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    delete_node(&a, 9);
    delete_node(&a, 5);
    delete_node(&a, 18);
    preorder(a);
    printf("\n");

}