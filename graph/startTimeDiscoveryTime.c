#include<stdio.h> 
#define WHITE 1
#define GREY 2
#define BLACK 3

int color[10];
int time = 1;
int sTime[10];
int fTime[10];

int adj[10][10];
int nodes, edges;

void dfsVisit(int x){
    color[x] = GREY;
    sTime[x] = time;
    time++;

    for(int i = 0; i < nodes; i++){
        if(adj[x][i] == 1){
            if(color[i] == WHITE){
                dfsVisit(i);
            }
        }
    }

    color[x] = BLACK;
    fTime[x] = time;
    time++;
    // printf("Nodes: %d  %d %d\n", x, sTime[x], fTime[x]);
}

void dfs(){
    for(int i = 0; i < nodes; i++){
        color[i] = WHITE;
    }

    dfsVisit(2);
}

int main()
{
    //pera nish na vai hisab korle eta easy e;
    freopen("input.txt", "r", stdin);
    int i, n1, n2;
    scanf("%d %d", &nodes, &edges);

    for(i = 0; i < nodes; i++){
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    dfs();

    for(i = 0; i < nodes; i++){
        printf("%c  %d %d\n", 65 + i, sTime[i], fTime[i]);
    }
    return 0;
}