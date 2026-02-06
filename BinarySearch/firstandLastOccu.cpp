#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sol1(vector<int> arr,int target){
    int n=arr.size();
    int first=-1,last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==target) {
            if(first==-1){
              first=i;}
            else {
                last=i;
            }

        }
    }
    return {{first,last}};
}

int lowerB( vector <int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]>=target) {
          ans=mid;
          high=mid-1;}
        else{
            low=mid+1;
        }


    }
    return ans;
}
int upperB( vector <int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]>target) {
          ans=mid;
          high=mid-1;}
        else{
            low=mid+1;
        }


    }
    return ans;
}

vector<vector<int>> sol2(vector<int> arr,int target){
    int n=arr.size();
    int lb=lowerB(arr,target);
    if(lb==n||arr[lb]!=target) return {{-1,-1}};
    return {{lb,upperB(arr,target)-1}};
}

int first (vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]==target) {
          ans=mid;
          high=mid-1;}
        else if(arr[mid]<target) low=mid+1;
        else{
            high=mid-1;
        }
    }
    return ans;
}
int last (vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]==target) {
          ans=mid;
          low=mid+1;}
        else if(arr[mid]<target) low=mid+1;
        else{
            high=mid-1;
        }
    }
    return ans;
}

vector<vector<int>> sol3(vector<int> arr,int target){
    
    int first1=first(arr,target);
    if (first1==-1) return {{-1,-1}};
    int last1=last(arr,target);
    return {{first1,last1}};


    // to find ouccerence of target digit 
    // (last-first+1)
}
int main(){
  int key = 13;

  vector<int> v = {3, 4, 13, 13, 13, 20, 40};
   vector<vector<int>> ans=sol3(v,key);
   cout<<ans[0][0]<<" "<<ans[0][1];

    return 0;
}