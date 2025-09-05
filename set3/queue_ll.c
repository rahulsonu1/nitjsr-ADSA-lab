#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };
struct Node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node* t=malloc(sizeof(struct Node));
    t->data=x; t->next=front;
    if(!front) front=rear=t, rear->next=front;
    else rear->next=t, rear=t, rear->next=front;
}

void dequeue(){
    if(!front) printf("Empty\n");
    else if(front==rear){
        printf("Deleted %d\n",front->data);
        free(front); front=rear=NULL;
    }else{
        struct Node* t=front;
        printf("Deleted %d\n",t->data);
        front=front->next; rear->next=front; free(t);
    }
}

void display(){
    if(!front) {printf("Empty\n"); return;}
    struct Node* t=front;
    do{ printf("%d ",t->data); t=t->next; }while(t!=front);
    printf("\n");
}

int main(){
    enqueue(10); enqueue(20); enqueue(30);
    display(); dequeue(); display();
    
}
