#include<bits/stdc++.h>
using namespace std;
int shiftL(int arr[],int n){
 int ele=arr[0];
 for(int i=0;i<n;i++){
    arr[i]=arr[i+1];
 }
 arr[n-1]=ele;
}


int main(){
        int arr[]={2,7,4,6,20,1,14,10,3};
    int n=sizeof(arr)/sizeof(arr[0]);

   shiftL(arr,n);
   
for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";
 }

 
    return 0;

}