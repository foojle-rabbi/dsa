#include<stdio.h>
#include<limits.h>

#define size 10
#define WHITE 1
#define GREY 2
#define BLACK 3

int adj[size][size];
int nodes, edges, i;

int parents[size];
int distance[size];
int color[size];

typedef struct{
    int data[size];
    int front;
    int rear;
} queue;

int isEmpty(queue *q){
    if(q->front == -1){
        return 1;
    }

    return 0;
}

void push(queue *q, int data){
    if(q->front == -1){
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % size;
    q->data[q->rear] = data;
}

int pop(queue *q){
    int val = -1;
    if(isEmpty(q)){
        return val;
    }

    val = q->data[q->front];

    if(q->front == q->rear){
        q->front = q->rear = -1;
    }

    q->front = (q->front + 1) % size;

    return val;
    
}

void bfs(int startingNode){
    queue q;
    q.front = -1;
    q.rear = -1;

    for(i = 0; i < nodes; i++){
        color[i] = WHITE;
        distance[i] = INT_MIN;
        parents[i] = -1;
    }

    distance[startingNode] = 0;
    parents[startingNode] = -1;

    push(&q, startingNode);

    while (!isEmpty(&q))
    {
        int x = pop(&q);

        if(color[x] == WHITE)
        {
        color[x] = GREY;
        printf("%d ", x);

        for(i = 0; i < nodes; i++){
            if(adj[x][i] == 1){
                if(color[i] == WHITE){
                    parents[i] = x;
                    distance[i] = distance[x] + 1;
                    push(&q, i);
                }
            }
        }

        color[x] = BLACK;
    }
    }
    
}

int main()
{
    freopen("input2.txt", "r", stdin);
    int n1, n2;

    scanf("%d %d", &nodes, &edges);
    for(i = 0; i < edges; i++){
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    bfs(0);
    return 0;
}