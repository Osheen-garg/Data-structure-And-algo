#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> fun(vector<int> arr,int target){
  int  n=arr.size();
  for(int i=1;i<n;i++){
    if(arr[i-1]+arr[i]==target){
        return {i-1,i};
    }
  }
  return {-1,-1};
}
int main(){
    vector<int>arr={4,3,2,6,0,4,1};
     vector<int>ans=fun(arr,5);
     for(auto i:ans){
        cout<<i<<" ";
     }
    return 0;
}