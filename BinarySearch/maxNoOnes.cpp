#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(vector<vector<int>>matrix){
  int n=matrix.size();
  int m=matrix[0].size();
  int cnt_max=-1;
  int index=-1;
  for(int i=0;i<n;i++){
    int cnt_one=0;
    for(int j=0;j<m;j++){
        if(matrix[i][j]==1){
            cnt_one+=1;
        }
    }
    if(cnt_max<cnt_one){
        cnt_max=cnt_one;
        index=i;
    }
  }
  return index;
}


int lowerbound(vector<int> arr,int n,int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
    int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int sol2(vector<vector<int>>matrix){
    int n=matrix.size();
  int m=matrix[0].size();
  int cnt_max=0;
  int index=-1;
  for(int i=0;i<n;i++){
    int cnt_one=m-lowerbound(matrix[i],m,1);
    if(cnt_one>cnt_max){
        cnt_max=cnt_one;
        index=i;
    }
  }
  return index;
}

int main(){
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << "The row with maximum no. of 1's is: " << sol2(matrix) << '\n';
    return 0;
}