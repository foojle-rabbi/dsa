#include<stdio.h> 

int adj[100][100];

int main()
{
    int i, j, n1, n2, nodes, edges;
    
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);

    for(i = 0; i < edges; i++){
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    for(i = 0; i < nodes; i++){
        for(j = 0; j < nodes; j++){
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}