#include <stdio.h>
#define INF 99999
#define V 4

int main() {
    int dist[V][V] = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            printf("%4d ", dist[i][j]==INF?999:dist[i][j]);
        printf("\n");
    }
}
