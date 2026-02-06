#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
}


void insertionS(int arr[],int n){
for(int i=0;i<n;i++){
    int j=i;        

        while (j>0 && arr[j-1]>arr[j])
        {
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
        
    }
    printarr(arr,n);

}




int main(){
    int arr[]={2,7,4,6,1,14,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionS(arr,n);
    return 0;
}