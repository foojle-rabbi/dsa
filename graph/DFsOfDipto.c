#include<stdio.h> 
#define white 1
#define grey 2
#define black 3

int adj[100][100];
int nodes;
int edges;
int color[100];

void dfsVisit(int x){
    color[x] = grey;

    for(int i = 0; i < nodes; i++){
        if(adj[x][i] == 1){
            if(color[i] == white){
                dfsVisit(i);
            }
        }
    }
    color[x] = black;
    printf("%d ", x);
}

void dfs(){
    for(int i = 0; i < nodes; i++){
        color[i] = white;
    }

    for(int i = 0; i < nodes; i++){
        if(color[i] == white){
            dfsVisit(i);
        }
    }
}

int main()
{
    //DFS means depth first search

    //important notes you cant declare global variabe i and use it to all the function for this 
    //purticular things. cause if you do the dfs visit function will not call for each nodes
    freopen("input.txt", "r", stdin);
    int i, n1, n2;

    scanf("%d %d", &nodes, &edges);
    for(i = 0; i < edges; i++){
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    dfs();
    return 0;
}