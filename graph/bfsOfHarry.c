#include<stdio.h> 
#define MAX 10

int adj[10][10];
int nodes, edges;
int visited[10];

//queue datas
struct queue{
    int data[MAX];
    int front;
    int rear;
};

int isEmpty(struct queue *q){
    if(q->front == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct queue *q, int data){
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = data;
}

int pop(struct queue *q){
    int val = q->data[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    q->front = (q->front + 1) % MAX;

    return val;
}

void bfs(int startingNode){
    struct queue q;
    q.front = -1;
    q.rear = -1;

    push(&q, startingNode);
    printf("%d ", startingNode);
    visited[startingNode] = 1;

    while(!isEmpty(&q)){
        int x = pop(&q);

        for(int i = 0; i < nodes; i++){
            if(adj[x][i] ==1 && visited[i] == 0){
                visited[i] = 1;
                printf("%d ", i);
                push(&q, i);
            }
        }
    }
}

int main()
{
    freopen("input2.txt", "r", stdin);
    scanf("%d %d", &edges, &nodes);

    for(int i = 0; i < edges; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    bfs(0);
    return 0;
}