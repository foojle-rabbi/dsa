#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* createNode(int data){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    if(new == NULL){
        printf("Couldn't create node\n");
        exit(1);
    }

    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void insert(int data){
    struct node* new = createNode(data);
    if(root == NULL){
        root = new;
        return;
    }

    struct node* prev = NULL;
    struct node* current = root;

    while(current != NULL){
        prev = current;
        if(current->data == data){
            printf("Value exits\n");
            return;
        }else if(current->data > data){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(prev->data > data){
        prev->left = new;
    }else{
        prev->right = new;
    }
}

void traversal(struct node* root){
    if(root != NULL){
        traversal(root->left);
        printf("%d ", root->data);
        traversal(root->right);
    }
}

struct queue{
    int data;
    struct node* next;
};

//Queue implement
struct queue *front = NULL;
struct queue* rear = NULL;

void push(struct node* root){
    struct node* new = root;
    if(front == NULL){
        front = rear = new;
    }else{
        rear->next = new;
        rear = new;
    }//baki ache vai kichui toh valo kore bujhi nai
}

int isEmpty(){
    if(front == NULL){
        return 1;
    }else{
        return 0;
    }
}

struct node* pop(){
    struct node* temp = front;
    front = front->next;

    return temp;
}

void levelOrder(struct node* root){

}

int main()
{
    root = NULL;

    insert(55);
    insert(40);
    insert(80);
    insert(34);
    insert(28);
    insert(38);
    insert(60);
    insert(90);

    // traversal(root);
    // levelOrder(root);
    printf("%d ", isEmpty());
    return 0;
}