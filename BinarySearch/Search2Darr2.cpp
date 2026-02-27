#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2; 
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

bool sol1(vector<vector<int>>arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        if(binarySearch(arr[i],target)) return true;
    }
    return false;
}

bool sol2(vector<vector<int>>arr,int target){
     int n=arr.size();
    int m=arr[0].size();
    int row=0;
    int col=m-1;
    while (row<n && col>=0)
    {
      if(arr[row][col]==target) return true;
      else if(arr[row][col]<target) row++;
      else col--;
    }
    return false;
    
}


int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    bool found = sol2(matrix,9);

    cout << (found ? "true\n" : "false\n");
    return 0;
}