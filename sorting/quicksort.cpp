#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int Partition_qs(int arr[],int low,int high){
int pivot=arr[low];
int i=low;
int j=high;
while(i<j){
 while (pivot>=arr[i] && i<=high-1)
 {
    i++;
 }
 while(pivot<arr[j] && j>=low+1){
    j--;
 }
 if(i<j){
        swap(arr[i],arr[j]);
    }
}
swap(arr[low],arr[j]);
return j;
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
}
void QuickSort(int arr[],int low,int high){
    if(low<high) {
    int Pindex=Partition_qs(arr,low,high);
    QuickSort(arr,low,Pindex-1);
    QuickSort(arr,Pindex+1,high);
    }
}
int main(){
      int arr[]={2,7,4,6,1,14,10};
    int n=sizeof(arr)/sizeof(arr[0]);
      QuickSort(arr,0,n-1);
     printarr(arr,n);
    return 0;
}