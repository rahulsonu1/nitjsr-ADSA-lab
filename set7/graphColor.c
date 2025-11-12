#include <stdio.h>
#include <stdlib.h>

int n, m;
int **adj;
int *color;

int safe(int v, int c){
    for(int u=0; u<n; ++u)
        if(adj[v][u] && color[u]==c) return 0;
    return 1;
}

int solve(int v){
    if(v==n) return 1;
    for(int c=1;c<=m;++c){
        if(safe(v,c)){
            color[v]=c;
            if(solve(v+1)) return 1;
            color[v]=0;
        }
    }
    return 0;
}

int main(){
    if(scanf("%d %d",&n,&m)!=2) return 0;
    adj = malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        adj[i]=malloc(n*sizeof(int));
        for(int j=0;j<n;j++) scanf("%d",&adj[i][j]);
    }
    color = calloc(n, sizeof(int));
    if(solve(0)){
        printf("Coloring:\n");
        for(int i=0;i<n;i++) printf("%d ", color[i]);
        printf("\n");
    } else printf("No solution\n");
    for(int i=0;i<n;i++) free(adj[i]);
    free(adj); free(color);
    return 0;
}
