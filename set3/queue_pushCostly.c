#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int s1[SIZE], s2[SIZE], top1=-1, top2=-1;

void pushStack(int *s, int *top, int x){ s[++(*top)]=x; }
int popStack(int *s, int *top){ return s[(*top)--]; }

void enqueue(int x){
    while(top1!=-1) pushStack(s2,&top2,popStack(s1,&top1));
    pushStack(s1,&top1,x);
    while(top2!=-1) pushStack(s1,&top1,popStack(s2,&top2));
}

int dequeue(){ return (top1==-1)?-1:popStack(s1,&top1); }

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    printf("%d ",dequeue()); printf("%d\n",dequeue());
}
