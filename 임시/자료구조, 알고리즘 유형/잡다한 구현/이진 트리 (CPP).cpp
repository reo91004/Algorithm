#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int key;
    struct treenode *leftchild;
    struct treenode *rightchild;
} treenode;

treenode *rootnode(treenode *root, int key)
{
    root->key = key;
    root->leftchild = NULL;
    root->rightchild = NULL;
    return root;
}

treenode *add_left(treenode *parent, int key)
{
    treenode *newnode;
    newnode = (treenode *)malloc(sizeof(treenode));
    newnode->key = key;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;

    parent->leftchild = newnode;
    return parent;
}

treenode *add_right(treenode *parent, int key)
{
    treenode *newnode;
    newnode = (treenode *)malloc(sizeof(treenode));
    newnode->key = key;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;

    parent->rightchild = newnode;
    return parent;
}

void print_tree(treenode *root)
{
    printf("%d ->", root->key);
    if (root->leftchild != NULL)
        print_tree(root->leftchild);
    if (root->rightchild != NULL)
        print_tree(root->rightchild);
}

int main()
{
    treenode *root = (treenode*)malloc(sizeof(treenode));
    root = rootnode(root, 4);
    root = add_left(root, 2);
    root = add_right(root, 3);
    
    root->leftchild = add_left(root->leftchild, 1);
    root->leftchild = add_right(root->leftchild, 5);
    root->leftchild->rightchild = add_left(root->leftchild->rightchild, 1);
    root->leftchild->rightchild = add_right(root->leftchild->rightchild, 7);
    print_tree(root);

    return 0;
}