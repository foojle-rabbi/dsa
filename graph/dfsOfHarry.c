#include<stdio.h>

int adj[10][10];
int nodes, edges;
int visited[10];

void dfsVisit(int x){
    printf("%d ", x);
    visited[x] = 1;

    for(int i = 0; i < nodes; i++){
        if(adj[x][i] == 1 && visited[i] == 0){
            dfsVisit(i);
        }
    }
}

void dfs(){
    for(int i = 0; i < nodes; i++){
        if(visited[i] == 0){
            dfsVisit(i);
        }
    }
}

int main()
{
    //this implement is taken form harrys video
    freopen("input2.txt", "r", stdin);
    scanf("%d %d", &edges, &nodes);

    int n1, n2;
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    dfs();
    return 0;
}