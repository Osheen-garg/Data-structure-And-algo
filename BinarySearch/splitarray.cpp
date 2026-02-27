#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Same code for the problem Painter's Partition Problem
int minlargestsum(vector <int> arr,int sum){
   int partition=1;
   int sumOfElement=0;
   for(int i=0;i<arr.size();i++){
    if(sumOfElement+arr[i]<=sum){
        sumOfElement+=arr[i];
    }else{
        partition++;
        sumOfElement=arr[i];
    }
   }
   return partition;
}

int sol1(vector<int> arr,int k){
    if(arr.size()<k) return 0;
    int low=*max_element(arr.begin(),arr.end());
    int maxi=accumulate(arr.begin(),arr.end(),0);
    for(int i=low;i<=maxi;i++){
        if(minlargestsum(arr,i)==k)  return i;
    }
    return low;
}
int sol2(vector<int> arr,int k){
    if(arr.size()<k) return 0;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
       
while (low<=high){
    int mid=(low+high)/2;
    if(minlargestsum(arr,mid)>k){
        low=mid+1;
    }else high=mid-1;
}
    return low;
}

int main(){
vector<int> a = {10, 20, 30, 40};
    int k = 2;
  int ans = sol2(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;

}