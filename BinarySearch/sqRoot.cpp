#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(int n){
int ans=-1;
for(int i=1;i<n/2;i++){
    if((long long )i*i<=n){
        ans=i;
    }
    else break;
}
return ans;
}

int sol2(int n){
    int ans=0;
    int left=1;
    int right=n/2;
    while(left<=right){
        int mid=(left+right)/2;
        if(mid*mid <=n){
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    return ans;
}

int main(){
    cout<<sol2(90);
    return 0;
}