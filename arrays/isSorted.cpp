#include<bits/stdc++.h>
using namespace std;

bool isSortedp(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){   // complexity O(N)
            return false;
        }
        return true;
    }
    
}


bool isSorted(int arr[],int n){
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[i]){    //complexitiy n**2
        return false;
        }
    }
    return true;
}
}
int main(){
        int arr[]={2,7,4,6,20,1,14,10,3};
        int arr1[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int num=isSortedp(arr1,n);
//    int num=isSorted(arr1,n);
   cout<<num;

    return 0;
}