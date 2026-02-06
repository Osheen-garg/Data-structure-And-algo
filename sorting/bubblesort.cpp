#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
}


void swap(int arr[],int n){
for(int i=0;i<n;i++){
     bool flag=false;

    for(int j=0;j<n-i-1;j++){

        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=true;
        }
            if(!flag) break;
    }

}
printarr(arr,n);

}
int main(){
    int arr[]={2,7,4,6,1,14,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    swap(arr,n);
    return 0;
}