#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack Stack;
struct stack{
    int *data;
    int top;
    int size;
};

bool isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

bool isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(Stack *s, int data){
    if(isFull(s)){
        printf("The stack is full\n");
        return;
    }
    s->top += 1;
    s->data[s->top] = data;
    printf("successfully pushed %d\n", s->data[s->top]);
}

void pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("successfully poped %d\n", s->data[s->top]);
    s->top--;
}

int main(){
    struct stack s1;
    s1.size = 5;
    s1.data = (int *) malloc ((s1.size -1 )* sizeof(int));
    s1.top = -1;

    pop(&s1);
    push(&s1,5);
    push(&s1,10);
    push(&s1,20);
    push(&s1,30);
    push(&s1,40);
    push(&s1,10);
    push(&s1,10);
    
    
    
    return 0;
}