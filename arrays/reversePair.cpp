#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sol1(vector<int> &arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j]) cnt++;
        }
    }
    return cnt;
}

void merge(vector<int> &arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
             temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high)
    {
         temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
int countPairs(vector<int> &arr,int low,int mid,int high){
    int cnt=0;
int right=mid+1;
for(int i=low;i<=mid;i++){
    while(right<=high && arr[i]>2*arr[right]) right++;
    cnt+=(right - (mid + 1));
    
}
return cnt;}
int mergeSort(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(int)(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}


int sol2(vector<int> &arr){
    int n=arr.size();
    return mergeSort(arr,0,n-1);
}

int main(){
     vector<int> a = {4, 1, 2, 3, 1};
    int cnt = sol2(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}