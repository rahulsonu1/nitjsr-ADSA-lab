#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

// 1. Insertion Sort
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key) a[j+1]=a[j--];
        a[j+1]=key;
    }
}

// 2. Bubble Sort
void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
}

// 3. Selection Sort
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++) if(a[j]<a[min]) min=j;
        swap(&a[i],&a[min]);
    }
}

// 4. Shell Sort
void shellSort(int a[],int n){
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;i++){
            int temp=a[i],j=i;
            while(j>=gap && a[j-gap]>temp) a[j]=a[j-gap], j-=gap;
            a[j]=temp;
        }
}

// 5. Quick Sort
int partition(int a[],int l,int h){
    int pivot=a[h],i=l-1;
    for(int j=l;j<h;j++) if(a[j]<pivot) swap(&a[++i],&a[j]);
    swap(&a[i+1],&a[h]);
    return i+1;
}
void quickSort(int a[],int l,int h){
    if(l<h){int p=partition(a,l,h); quickSort(a,l,p-1); quickSort(a,p+1,h);}
}

// 6. Merge Sort
void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) a[k++]=(L[i]<=R[j]?L[i++]:R[j++]);
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[],int l,int r){
    if(l<r){int m=l+(r-l)/2; mergeSort(a,l,m); mergeSort(a,m+1,r); merge(a,l,m,r);}
}

// 7. Heap Sort
void heapify(int a[],int n,int i){
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){swap(&a[i],&a[largest]); heapify(a,n,largest);}
}
void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){swap(&a[0],&a[i]); heapify(a,i,0);}
}

// 8. Counting Sort
void countingSort(int a[],int n){
    int max=a[0]; for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    int c[max+1]; memset(c,0,sizeof(c));
    for(int i=0;i<n;i++) c[a[i]]++;
    for(int i=1;i<=max;i++) c[i]+=c[i-1];
    int b[n];
    for(int i=n-1;i>=0;i--) b[--c[a[i]]]=a[i];
    for(int i=0;i<n;i++) a[i]=b[i];
}

// 9. Radix Sort (LSD)
int getMax(int a[],int n){int mx=a[0];for(int i=1;i<n;i++) if(a[i]>mx) mx=a[i]; return mx;}
void countSortRadix(int a[],int n,int exp){
    int b[n],i,c[10]={0};
    for(i=0;i<n;i++) c[(a[i]/exp)%10]++;
    for(i=1;i<10;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) b[--c[(a[i]/exp)%10]]=a[i];
    for(i=0;i<n;i++) a[i]=b[i];
}
void radixSort(int a[],int n){
    int m=getMax(a,n);
    for(int exp=1;m/exp>0;exp*=10) countSortRadix(a,n,exp);
}

// 10. Bucket Sort (simple for 0..99)
void bucketSort(int a[],int n){
    int b[100]={0};
    for(int i=0;i<n;i++) b[a[i]]++;
    int k=0;
    for(int i=0;i<100;i++) for(int j=0;j<b[i];j++) a[k++]=i;
}

// 11. Radix Exchange Sort (binary MSD)
void radixExchangeSort(int a[],int l,int r,int bit){
    if(bit<0 || l>=r) return;
    int i=l,j=r;
    while(i<=j){
        while(i<=r && !(a[i]&(1<<bit))) i++;
        while(j>=l && (a[j]&(1<<bit))) j--;
        if(i<j) swap(&a[i],&a[j]);
    }
    radixExchangeSort(a,l,j,bit-1);
    radixExchangeSort(a,i,r,bit-1);
}

// 12. Address Calculation Sort (simple simulation using hash array)
void addressCalcSort(int a[],int n){
    int max=a[0]; for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    int h[max+1]; memset(h,0,sizeof(h));
    for(int i=0;i<n;i++) h[a[i]]=a[i];
    int k=0;
    for(int i=0;i<=max;i++) if(h[i]) a[k++]=h[i];
}

// Helper to print array
void printArr(int a[],int n){for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n");}

int main(){
    int arr[]={29,10,14,37,13,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int a[n];

    memcpy(a,arr,sizeof(arr)); insertionSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); bubbleSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); selectionSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); shellSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); quickSort(a,0,n-1); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); mergeSort(a,0,n-1); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); heapSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); countingSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); radixSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); bucketSort(a,n); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); radixExchangeSort(a,0,n-1,31); printArr(a,n);
    memcpy(a,arr,sizeof(arr)); addressCalcSort(a,n); printArr(a,n);

    return 0;
}
