#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int isEmpty(struct node *f){
    if(f==NULL){
        return 1;
    }
    return 0;
}

struct node *createNode(int data){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory error\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;

    return new;
}

void push(struct node **f, int data){
    struct node *new = createNode(data);
    new->next = (*f);
    (*f) = new;
}

void display(struct node *f){
    printf("Element of stack: ");
    while(f != NULL){
        printf("%d ", f->data);
        f = f->next;
    }
    printf("\n");
}

void pop(struct node **f){
    if(isEmpty(*f)){
        printf("staack is empty\n");
        return;
    }
    struct node *temp = *f;
    *f = (*f)->next;
    free(temp);
}

int top(struct node*f){
    if(isEmpty(f)){
        printf("Stack is empty\n");
    }
    return f->data;
}

int bottom(struct node *f){
     if(isEmpty(f)){
        printf("Stack is empty\n");
    }
    struct node *ptr = f;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    return ptr->data;
}

int main() {
    struct node *f = NULL;

    push(&f, 10);
    push(&f, 20);
    push(&f, 30);
    push(&f, 40);
    printf("top value is %d\n", top(f));
    printf("bottom value is %d\n", bottom(f));
    
    return 0;
}