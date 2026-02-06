#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void swap(int arr[],int n){

    if(n==1) return;
     int flag=0;

for(int j=0;j<n-1;j++){

        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=1;
        }
    }
if(flag==0) return;
swap(arr,n-1);

}


int main(){
    int arr[]={2,7,4,6,1,14,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    swap(arr,n);
    printarr(arr,n);

    return 0;
}