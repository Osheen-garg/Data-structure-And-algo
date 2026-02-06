#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int floorx(vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]<=target){
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int ceilx(vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)/2);
        if(arr[mid]>=target){
            ans=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector <int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    int first=floorx(arr,x);
    int second=ceilx(arr,x);
    cout << "The floor and ceil are: " << first << " " << second << endl;
    return 0;

}