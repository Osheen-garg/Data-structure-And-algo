#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(vector <int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        bool left= (i==0)||(arr[i]>arr[i-1]);
        bool right=(i==n-1)||(arr[i]>arr[i+1]);
        if(left && right) return i;
    }
}

int sol2(vector<int> arr){
    int n=arr.size();
    if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;

    int low=1;
    int high=n-2;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1]&& arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return -1;
    
}

int sol3(vector <int> arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid+1]){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    
}

int main(){
    vector<int> nums = {1, 3, 20, 4, 1, 0};
    int index = sol3(nums);
    cout << "Peak at index: " << index << " with value: " << nums[index] << endl;

    return 0;
}