#include<bits/stdc++.h>
using namespace std;
 
//optimized code to find second larget and second smallest

int sS(int arr[],int n){
  int small=INT_MAX;
  int secondSmall=INT_MAX;
  for(int i=0;i<n;i++){
    if(small>arr[i]){
        secondSmall=small;
        small=arr[i];
    }
    else if(secondSmall>arr[i] && arr[i]!=small){
        secondSmall=arr[i];
    }
  }
  return secondSmall;
}

int sL(int arr[],int n){
 int large=INT_MIN;
  int secondLarge=INT_MIN;
  for(int i=0;i<n;i++){
    if(large<arr[i]){
        secondLarge=large;
        large=arr[i];
    }
    else if(secondLarge<arr[i] && arr[i]!=large){
        secondLarge=arr[i];
    }
  }
  return secondLarge;
}


int secondLargest(int arr[],int n){
     int max=arr[0];
     for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
         }
     }
    //  cout<<max;
     int max2=arr[0];
     for(int i=1;i<n;i++){
        if(max2<arr[i] && arr[i]!=max){
            max2=arr[i];
        }
     }
     return max2;
}

int main(){
            int arr[]={8,7,4,6,20,1,14,10,3};
    int n=sizeof(arr)/sizeof(arr[0]);

//    int num=secondLargest(arr,n);
//    cout<<num;
cout<<sS(arr,n)<<endl;
cout<<sL(arr,n)<<endl;

    return 0;
}