#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// same lower bound code for binary search insert 
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

int main(){
     vector<int> arr = {3, 5, 8, 15, 19};  
    int x = 8;
    // int ind =lowerB(arr, x);  
    int ind =upperB(arr, x); 

    cout << "The lower bound is the index: " << ind << "\n";  
    return 0;
}