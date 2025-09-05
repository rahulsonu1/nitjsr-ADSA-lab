#include <stdio.h>
#include <stdlib.h>

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
    for(int size=1;size<n;size*=2)
        for(int l=0;l<n-1;l+=2*size){
            int m=l+size-1,r=l+2*size-1;
            if(m<n-1){
                if(r>=n)r=n-1;
                merge(a,l,m,r);
            }
        }
}
int main(){
    int a[]={38,27,43,3,9,82,10},n=7;
    mergeSort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}
