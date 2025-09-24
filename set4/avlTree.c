#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;

int h(Node* n){ return n ? n->height : 0; }
int max(int a,int b){ return a>b?a:b; }

Node* newNode(int k){
    Node* n=malloc(sizeof(Node));
    n->key=k; n->left=n->right=NULL; n->height=1;
    return n;
}

Node* rotateRight(Node* y){
    Node* x=y->left; Node* T=x->right;
    x->right=y; y->left=T;
    y->height=max(h(y->left),h(y->right))+1;
    x->height=max(h(x->left),h(x->right))+1;
    return x;
}
Node* rotateLeft(Node* x){
    Node* y=x->right; Node* T=y->left;
    y->left=x; x->right=T;
    x->height=max(h(x->left),h(x->right))+1;
    y->height=max(h(y->left),h(y->right))+1;
    return y;
}
int bf(Node* n){ return n? h(n->left)-h(n->right):0; }

Node* insertItem(Node* root,int key){
    if(!root) return newNode(key);
    if(key<root->key) root->left=insertItem(root->left,key);
    else if(key>root->key) root->right=insertItem(root->right,key);
    else return root; // no duplicates

    root->height=1+max(h(root->left),h(root->right));
    int balance=bf(root);

    if(balance>1 && key<root->left->key) return rotateRight(root);
    if(balance<-1 && key>root->right->key) return rotateLeft(root);
    if(balance>1 && key>root->left->key){ root->left=rotateLeft(root->left); return rotateRight(root); }
    if(balance<-1 && key<root->right->key){ root->right=rotateRight(root->right); return rotateLeft(root); }
    return root;
}

Node* minValue(Node* n){
    while(n->left) n=n->left;
    return n;
}

Node* deleteItem(Node* root,int key){
    if(!root) return root;
    if(key<root->key) root->left=deleteItem(root->left,key);
    else if(key>root->key) root->right=deleteItem(root->right,key);
    else {
        if(!root->left||!root->right){
            Node* temp=root->left?root->left:root->right;
            if(!temp){ free(root); return NULL; }
            *root=*temp; free(temp);
        } else {
            Node* t=minValue(root->right);
            root->key=t->key;
            root->right=deleteItem(root->right,t->key);
        }
    }
    root->height=1+max(h(root->left),h(root->right));
    int balance=bf(root);

    if(balance>1 && bf(root->left)>=0) return rotateRight(root);
    if(balance>1 && bf(root->left)<0){ root->left=rotateLeft(root->left); return rotateRight(root); }
    if(balance<-1 && bf(root->right)<=0) return rotateLeft(root);
    if(balance<-1 && bf(root->right)>0){ root->right=rotateRight(root->right); return rotateLeft(root); }
    return root;
}

Node* searchItem(Node* r,int k){
    if(!r||r->key==k) return r;
    return k<r->key? searchItem(r->left,k): searchItem(r->right,k);
}

void deleteTree(Node* r){ if(r){ deleteTree(r->left); deleteTree(r->right); free(r);} }
Node* createTree(){ return NULL; }

void preorder(Node* r){ if(r){ printf("%d ",r->key); preorder(r->left); preorder(r->right);} }

int main(){
    Node* root=createTree();
    root=insertItem(root,10);
    root=insertItem(root,20);
    root=insertItem(root,30);
    root=insertItem(root,40);
    root=insertItem(root,50);
    root=insertItem(root,25);

    printf("Preorder: "); preorder(root); printf("\n");

    root=deleteItem(root,40);
    printf("After delete 40: "); preorder(root); printf("\n");

    Node* f=searchItem(root,25);
    printf("Search 25: %s\n",f?"Found":"Not Found");

    deleE teTree(root);
    return 0;
}
