#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
}

void selectionS(int arr[],int n){

  for(int i=0;i<n-1;i++){
        int min=i;
    for(int j=i+1;j<n;j++){
         if(arr[min]>arr[j]){
           min=j;
         }

    }
     int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
  }
      printarr(arr,n);

}


int main(){
    int arr[]={2,7,4,6,1,14,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    selectionS(arr,n);
    return 0;
}