#include <stdio.h>
#include <limits.h>

struct Edge { int u, v, w; };

int main() {
    int V = 5, E = 8;
    struct Edge edges[] = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},
        {3,2,5},{3,1,1},{4,3,-3}
    };
    int dist[V]; 
    for(int i=0;i<V;i++) dist[i]=INT_MAX;
    dist[0]=0;

    for(int i=0;i<V-1;i++)
        for(int j=0;j<E;j++)
            if(dist[edges[j].u]!=INT_MAX && dist[edges[j].u]+edges[j].w<dist[edges[j].v])
                dist[edges[j].v]=dist[edges[j].u]+edges[j].w;

    for(int j=0;j<E;j++)
        if(dist[edges[j].u]!=INT_MAX && dist[edges[j].u]+edges[j].w<dist[edges[j].v])
            printf("Negative cycle!\n");

    for(int i=0;i<V;i++) printf("0 -> %d = %d\n",i,dist[i]);
}
