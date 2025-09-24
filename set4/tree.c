#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int d) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data=d; n->left=n->right=NULL;
    return n;
}
void preorder(struct Node* root) {
    if(!root) return;
    struct Node* stack[100]; int top=-1;
    stack[++top]=root;
    while(top!=-1) {
        struct Node* cur=stack[top--];
        printf("%d ",cur->data);
        if(cur->right) stack[++top]=cur->right;
        if(cur->left)  stack[++top]=cur->left;
    }
}
int main() {
    struct Node* r=newNode(1);
    r->left=newNode(2); r->right=newNode(3);
    r->left->left=newNode(4); r->left->right=newNode(5);
    preorder(r);
    return 0;
}
