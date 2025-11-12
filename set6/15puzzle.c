#include <stdio.h>
#include <stdlib.h>

int start[16], goal[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int path[1000], solved=0;
char moves[1000];
const int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
const char mchar[4]={'U','D','L','R'};

int manhattan(int s[]){
    int sum=0;
    for(int i=0;i<16;i++){
        int v=s[i];
        if(v==0) continue;
        int tr=(v-1)/4, tc=(v-1)%4;
        sum += abs(tr - i/4) + abs(tc - i%4);
    }
    return sum;
}

int inversions(int a[]){
    int cnt=0;
    for(int i=0;i<16;i++) for(int j=i+1;j<16;j++)
        if(a[i] && a[j] && a[i]>a[j]) cnt++;
    return cnt;
}

int dfs(int s[], int blank, int g, int bound, int prev){
    int h = manhattan(s);
    int f = g + h;
    if(f > bound) return f;
    if(h==0){ solved = g; return -1; }
    int min = 1<<30;
    int br = blank/4, bc = blank%4;
    for(int mv=0; mv<4; mv++){
        // avoid immediately undoing previous move
        if(prev>=0 && ((prev^1)==mv)) continue;
        int nr=br+dr[mv], nc=bc+dc[mv];
        if(nr<0||nr>3||nc<0||nc>3) continue;
        int nb = nr*4+nc;
        // apply move
        s[blank]=s[nb]; s[nb]=0;
        int t = dfs(s, nb, g+1, bound, mv);
        if(t==-1){ moves[g]=mchar[mv]; return -1; }
        if(t < min) min = t;
        // undo
        s[nb]=s[blank]; s[blank]=0;
    }
    return min;
}

int main(){
    for(int i=0;i<16;i++) if(scanf("%d",&start[i])!=1) return 0;
    // solvability check
    int inv = inversions(start);
    int blankRowFromBottom = 4 - ( (0<=0)?0:0 ); // placeholder
    int blankPos = 0;
    for(int i=0;i<16;i++) if(start[i]==0) { blankPos=i; break; }
    int rowFromBottom = 4 - (blankPos/4);
    // For even grid (4): solvable if (inversions + rowFromBottom) is even
    if( (inv + rowFromBottom) % 2 ){ printf("Unsolvable\n"); return 0; }

    int bound = manhattan(start);
    while(1){
        int copy[16];
        for(int i=0;i<16;i++) copy[i]=start[i];
        int t = dfs(copy, blankPos, 0, bound, -1);
        if(t==-1){
            for(int i=0;i<solved;i++) putchar(moves[i]);
            putchar('\n');
            printf("Moves: %d\n", solved);
            return 0;
        }
        if(t==1<<30){ printf("Unsolvable\n"); return 0; }
        bound = t;
    }
    return 0;
}
