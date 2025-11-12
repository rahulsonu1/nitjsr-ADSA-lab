#include <stdio.h>
#include <stdlib.h>

int n;
int *col; 

int safe(int row, int c){
    for(int r=0; r<row; ++r)
        if(col[r]==c || abs(col[r]-c)==row-r) return 0;
    return 1;
}

void print_sol(){
    for(int r=0;r<n;++r){
        for(int c=0;c<n;++c) putchar(col[r]==c ? 'Q' : '.');
        putchar('\n');
    }
    putchar('\n');
}

void solve(int row){
    if(row==n){ print_sol(); return; }
    for(int c=0;c<n;++c)
        if(safe(row,c)){ col[row]=c; solve(row+1); }
}

int main(){
    if(scanf("%d",&n)!=1 || n<=0) return 0;
    col = malloc(n * sizeof(int));
    solve(0);
    free(col);
    return 0;
}
