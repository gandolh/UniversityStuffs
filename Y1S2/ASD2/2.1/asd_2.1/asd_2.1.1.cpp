
#pragma warning(disable:4996)
typedef struct node {
    int key;
    struct node* left, * right;
} node;
typedef struct tree {
    node* root;

} tree;