#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int bn(vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int bnR(vector<int> arr,int low,int high,int target ){
    if(low>high) return -1;
    int mid=low+((mid-low)/2);
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) return bnR(arr,low,mid-1,target);
    return bnR(arr,mid+1,high,target);
}

int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int target = 6; // target element to search
int n=a.size();
     // Create object of Solution class
    // int ind = bn(a, target);
 int ind = bnR(a,0,n-1, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;


    return 0;
}
