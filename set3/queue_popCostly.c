#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int s1[SIZE], s2[SIZE], top1=-1, top2=-1;

void pushStack(int *s, int *top, int x){ s[++(*top)]=x; }
int popStack(int *s, int *top){ return s[(*top)--]; }

void enqueue(int x){ pushStack(s1,&top1,x); }

int dequeue(){
    if(top2==-1){
        if(top1==-1) return -1;
        while(top1!=-1) pushStack(s2,&top2,popStack(s1,&top1));
    }
    return popStack(s2,&top2);
}

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    printf("%d ",dequeue()); printf("%d\n",dequeue());
}
