#include <stdio.h>
#include <stdlib.h>

#define max 3

struct queue
{
    int *data;
    int front;
    int rear;
};

void display(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
    }
    int i = q->front;
    printf("Eleemnts of the Queue: ");
    while (i != q->rear)
    {
        printf("%d ", q->data[i]);
        i = (i + 1) % max;
    }
    printf("%d", q->data[q->rear]);
    printf("\n");
}

void enqueue(struct queue *q, int data)
{
    if ((q->rear + 1) % max == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % max;
    q->data[q->rear] = data;
}

void dequeue(struct queue *q){
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    if (q->rear == q->front)
    {
        q->rear = q->front = -1;
    }
    q->front = (q->front + 1) % max;
}

int main()
{

    struct queue Q;
    Q.data = (int *)malloc(max * sizeof(int));
    Q.front = -1;
    Q.rear = -1;

    dequeue(&Q);
    enqueue(&Q, 5);
    enqueue(&Q, 10);
    dequeue(&Q);
    

    display(&Q);

    return 0;

    // class channel
    // attr_reader name
}
