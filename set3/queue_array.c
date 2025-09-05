#include <stdio.h>
#define SIZE 5

int q[SIZE], front=-1, rear=-1;

void enqueue(int x){
    if((rear+1)%SIZE==front) printf("Full\n");
    else{
        if(front==-1) front=0;
        rear=(rear+1)%SIZE; q[rear]=x;
    }
}

void dequeue(){
    if(front==-1) printf("Empty\n");
    else{
        printf("Deleted %d\n",q[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1)%SIZE;
    }
}

void display(){
    if(front==-1) printf("Empty\n");
    else{
        int i=front;
        while(1){
            printf("%d ",q[i]);
            if(i==rear) break;
            i=(i+1)%SIZE;
        }
        printf("\n");
    }
}


int main(){
    enqueue(10); enqueue(20); enqueue(30);
    enqueue(284);enqueue(4334);;enqueue(433);
    display(); dequeue(); display();
    printf("%d",size());
}
