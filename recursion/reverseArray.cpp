#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
      cout<<arr[i]<<endl;
    }
}
void reverseArr(int arr[],int n){
        int ans[n];
        for(int i=0;i<n;i++){
            ans[n-i-1]=arr[i];
        }
   printArray(ans,n);
    }

int main(){
    int n=5;
    int arr[5]={2,4,5,8,9};
    reverseArr(arr,n);
    return 0;
}