#include<iostream>
#include<bits\stdc++.h>
using namespace std;

int dayneed(vector<int> arr,int cap){
  int day=1;
  int loadCap=0;
  for(auto w:arr){
    if(loadCap+w>cap){
        day++;
        loadCap=w;
    }
    else{
        loadCap+=w;
    }
  }
  return day;
}
int sol1(vector<int> arr,int days){
    int left=*max_element(arr.begin(),arr.end());
    int right=accumulate(arr.begin(),arr.end(),0);
    for(int i=left;i<=right;i++){
        if(dayneed(arr,i)<=days){
            return i;
        }
    }
    return -1;
}

int sol2(vector<int>arr,int days){
    int left=*max_element(arr.begin(),arr.end());
    int right=accumulate(arr.begin(),arr.end(),0);
    while (left<right){
        int mid=(left+right)/2;
         if(dayneed(arr,mid)<=days){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
    
}

int main(){
        vector<int> weights = {5,4,5,2,3,4,5,6};
    int d = 5;
    cout << sol2(weights, d) << "\n";

    return 0;
}