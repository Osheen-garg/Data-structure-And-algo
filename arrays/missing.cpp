#include<bits/stdc++.h>
using namespace std;
//TC O(n*n)
//SC O(1)
int missing(int arr[],int n){
    
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<=n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
    
}

//TC O(2N)
//SC O(n)
int missinghash(int arr[],int n){
    int hash[n+1];

    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
}
//TC O(n)
int missingSum(int arr[],int n){
    int sum=(n*(n+1))/2;
int s=0;
    for(int i=0;i<n-1;i++){
        s+=arr[i];
    }
    return (sum-s);
    
}
//TC O(n)
int missingXOR(int arr[],int n){
    
  int xor1=0,xor2=0;
  for(int i=0;i<n-1;i++){
    xor2=xor2^arr[i];
    xor1=xor1^(i+1);
  }
  xor1=xor1^n;
  return(xor1 ^xor2);
    
}

int main(){
    int arr[]={1,2,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<missingXOR(arr,5);
    return 0;
}