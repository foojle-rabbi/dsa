#include<stdio.h> 
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node* head){
    printf("Elements of linked list: ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *createNode(int data){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    if(new == NULL){
        printf("Coudn't create node\n");
        exit(1);
    }

    new->data = data;
    new->next = NULL;

    return new;
}

struct node* insertAtFirst(struct node * head, int data){
    struct node* newNode = createNode(data);
    newNode->next = head;

    return newNode;
}

struct node* insertAtLast(struct node* head, int data){
    struct node *p = head;
    struct node* newNode = createNode(data);
    
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newNode;

    return head;
}

struct node* insertAtIndex(struct node* head, int data, int index){
    int i = 0;
    struct node * newNode = createNode(data);
    struct node* p = head;
    while(i != index -1){
        p = p->next;
        i++;
    }

    newNode->next = p->next;
    p->next = newNode;

    return head;
}

// deletion operations
struct node* deleteAtFirst(struct node * head){
    struct node *temp = head; 
    head = head->next;

    free(temp);

    return head;
}

struct node* deleteAtLast(struct node* head){
    struct node* p = head;
    struct node* q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

void deleteAtIndex(struct node* head, int index){
    int i = 0;
    struct node * p = head;
    struct node* q = head->next;

    while(i != index-1){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
}

//function e jhamela ache
struct node* deleteByValue(struct node* head, int value){
    struct node *p = head;
    struct node *q = head->next;

    if(q == NULL){
        head = NULL;
        return head;
    }

    while(q != NULL){
        if(q->data == value){
            printf("iam entering while loop\n");
            p->next = q->next;
            return head;
        }
        p = p->next;
        q = q->next;
    }
    return head;
}

//others operations
int lengthOfLinkedList(struct node* head){
    int length = 0;
    while(head != NULL){
        head = head->next;
        length++;
    }

    return length;
}

struct node* searchAValue(struct node* head, int key){
    while(head != NULL){
        if(head->data == key){
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int main() 
{
    struct node* head = createNode(15);
    display(head);
    
    head = insertAtFirst(head, 10);
    display(head);

    head = insertAtLast(head, 20);
    display(head);

    head = insertAtIndex(head, 12, 1);
    display(head);

    head = deleteByValue(head, 15);
    display(head);

    int key = 10;
    struct node* n = searchAValue(head, key);
    if(n == NULL){
        printf("%d is not found\n", key);
    }else{
        printf("%d is found\n", n->data);
    }

    printf("Length of the linked list is %d\n", lengthOfLinkedList(head));
    return 0;
}