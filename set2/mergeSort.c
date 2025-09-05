#include <stdio.h>
#include <stdlib.h>

typedef struct{int l,r,mid,stage;}Frame;
void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,L[n1],R[n2],i,j,k;
    for(i=0;i<n1;i++)L[i]=a[l+i];
    for(j=0;j<n2;j++)R[j]=a[m+1+j];
    i=j=0;k=l;
    while(i<n1&&j<n2)a[k++]=(L[i]<=R[j]?L[i++]:R[j++]);
    while(i<n1)a[k++]=L[i++];
    while(j<n2)a[k++]=R[j++];
}
void mergeSort(int a[],int n){
    Frame st[1000];int top=0;st[top++] = (Frame){0,n-1,0,0};
    while(top){
        Frame *f=&st[--top];
        if(f->l>=f->r)continue;
        if(!f->stage){
            f->mid=(f->l+f->r)/2;f->stage=1;st[top++]=*f;
            st[top++]=(Frame){f->l,f->mid,0,0};
            st[top++]=(Frame){f->mid+1,f->r,0,0};
        }else merge(a,f->l,f->mid,f->r);
    }
}
int main(){
    int a[]={38,27,43,3,9,82,10},n=7;
    mergeSort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}
