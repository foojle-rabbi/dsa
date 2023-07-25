#include<stdio.h> 

#define WHITE 1
#define GREY 2
#define BLACK 3

int adj[10][10];
int nodes, edges, i;
int color[10];

int time = 1;
int startingTime[100];
int finishingTime[100];

int data[20];
int top = -1;

void push(int value){
    top++;
    data[top] = value;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int pop(){
    int val = data[top];
    top--;

    return val;
}

void dfsVisit(int x){
    color[x] = GREY;
    startingTime[x] = time;
    time++;

    for(i = 0; i < nodes; i++){
        if(adj[x][i] ==1 && color[i] == WHITE){
            dfsVisit(i);
        }
    }

    color[x] = BLACK;
    finishingTime[x] = time;
    time++;
    push(x);
}

void dfs(){
    for(i = 0; i < nodes; i++){
        color[i] = WHITE;
    }

    for(i = 0; i < nodes; i++){
        if(color[i] == WHITE){
        dfsVisit(i);
        }
    }
}

int main()
{
    freopen("topological.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);

    int n1, n2;
    for(i = 0; i < edges; i++){
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    dfs();

    while(!isEmpty()){
        printf("%d ", pop());
    }
    return 0;
}