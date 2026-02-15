#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int calcTotalHours(vector<int>arr,int h){
  int totalHour=0;
  for(auto i:arr ){
    totalHour+=ceil((double)i/h);
  }
  return totalHour;
}

int sol1(vector<int> arr,int h){
    int maxVal=*max_element(arr.begin(),arr.end());
    for(int i=1;i<=maxVal;i++){
        int hours=calcTotalHours(arr,i);
        if(hours<=h) return i;
    }
    return maxVal;
}

int sol2(vector<int> arr,int h){
    int maxVal=*max_element(arr.begin(),arr.end());
    int low=1;
    int high=maxVal;
      int ans=maxVal;
    while (low<=high){
        int mid=(low+high)/2;
        int hours=calcTotalHours(arr,mid);
        if(hours<=h) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}


int main(){
     vector<int> a = {3, 6, 7, 11};
    int h = 8;
    cout << sol2(a, h);
    return 0;
}