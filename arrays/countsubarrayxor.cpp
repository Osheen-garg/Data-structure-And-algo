#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int> arr,int target){
  int n=arr.size();
  int count=0;
  for(int i=0;i<n;i++){
    int xorval=0;
    for(int j=i;j<n;j++){
        xorval^=arr[j];
        if(xorval==target) count++;
    }
  }
  return count;
}

int sol2(vector<int> arr,int target){
  int count=0;
  int prefixxor=0;
  unordered_map<int,int> mpp;
  mpp[0]=1;
  for(auto val: arr){
    prefixxor^=val;
    int k=prefixxor^target;
    if(mpp.find(k)!=mpp.end())
    {
        count+=mpp[k];
    }
    mpp[prefixxor]++;
  }
  return count;
}

int main(){
vector<int> A = {5, 6, 7, 8, 9};
    // Target xor
    int B = 5;

    cout << sol1(A, B) << endl;
    return 0;
}