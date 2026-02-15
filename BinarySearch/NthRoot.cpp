#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(int n,int m){
    int ans=-1;
    for(int i=1;i<=m;i++){
      long long power=pow(i,n);
      if(power==m) return i;
      if(power>m) break;
    }
    return ans;
}

int sol2(int n,int m){
    int low=1;
    int high=m;
    while (low<=high){
     long long mid=(low+high)/2;
     long long  ans=1;
     for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m) break;
     }
     if(ans==m) return mid;

     if(ans<m) low =mid+1;
     else high=mid-1;
    }
    return -1;
}

int main(){
    cout<<sol2(3,27);
    return 0;
}