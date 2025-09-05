#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int q1[SIZE], q2[SIZE], f1=-1,r1=-1,f2=-1,r2=-1;

void enqueue(int *q,int *f,int *r,int x){ q[++(*r)]=x; if(*f==-1)*f=0; }
int dequeue(int *q,int *f,int *r){ return q[(*f)++]; }

void push(int x){ enqueue(q1,&f1,&r1,x); }

int pop(){
    if(f1>r1) return -1;
    while(f1<r1) enqueue(q2,&f2,&r2,dequeue(q1,&f1,&r1));
    int val=dequeue(q1,&f1,&r1);
    f1=f2;r1=r2; for(int i=f2;i<=r2;i++) q1[i]=q2[i]; f2=r2=-1;
    return val;
}

int main(){
    push(10); push(20); push(30);
    printf("%d ",pop()); printf("%d\n",pop());
}
