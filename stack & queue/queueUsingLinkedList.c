#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    if(new == NULL){
        printf("Memory error\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;

    return new;
}

void enqueue(struct node **r, struct node **f, int data){
    struct node *new = createNode(data);
    if(*f==NULL){
        *f=*r=new;
    }else{
        (*r)->next= new;
        *r = (*r)->next;
    }
}

void display(struct node *f){
    if(f == NULL){
        printf("Nothing to display\n");
        return;
    }
    printf("Elemets of queue: ");
    while(f != NULL){
        printf("%d ", f->data);
        f = f->next;
    }
    printf("\n");
}

void dequeue(struct node **f){
    if(*f== NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp= *f;
    *f = (*f)->next;

    free(temp);
}

int main() {
    
    // struct node *queue;
    // queue = createQueue(5);
    struct node *r = NULL;
    struct node *f = NULL;

    enqueue(&r,&f, 5);
    enqueue(&r,&f, 10);
    enqueue(&r,&f, 15);
    enqueue(&r,&f, 20);

    display(f);

    dequeue(&f);
    dequeue(&f);
    dequeue(&f);
    dequeue(&f);
    dequeue(&f);
    display(f);
    
    return 0;
}
