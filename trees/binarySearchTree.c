#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

struct node *search(struct node *root, int value)
{
    if (root != NULL)
    {
        if (root->data == value)
        {
            return root;
        }
        else if (root->data > value)
        {
            return search(root->left, value);
        }
        else
        {
            return search(root->right, value);
        }
    }
    return NULL;
}

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insertAvalue(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        if (root->data == key)
        {
            printf("The value is already exists\n");
            return;
        }
        prev = root;
        if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (prev->data > key)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    struct node *root = createNode(6);
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(8);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(5);
    struct node *p5 = createNode(11);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    inorderTraversal(root);
    printf("\n");

    struct node *n = searchIter(root, 11);
    if (n == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("%d value is found\n", n->data);
    }
    insertAvalue(root, 11);
    inorderTraversal(root);

    return 0;
}
