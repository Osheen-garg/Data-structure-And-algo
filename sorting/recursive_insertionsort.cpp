#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
}

void insertionSR(int arr[],int j,int n){
    if(j==n) return;
    int i=j;
    while(i>0 && arr[i-1]>arr[i]){
        int temp=arr[i-1];
        arr[i-1]=arr[i];
        arr[i]=temp;
        i--;
    } 
    insertionSR(arr,j+1,n);


  
}
int main(){
      int arr[]={2,7,4,6,1,14,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionSR(arr,0,n);
     printarr(arr,n);
    return 0;
}