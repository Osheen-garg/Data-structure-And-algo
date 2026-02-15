#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countStu(vector<int> arr,int noPage){
    int n=arr.size();
    int stucount=1;
    int pagecount=0;
    for(int i=0;i<n;i++){
     if(pagecount+arr[i]<=noPage){
        pagecount+=arr[i];
     }else{
        stucount++;
        pagecount=arr[i];
     }

    }
    return stucount;
}


int sol1(vector<int> arr,int stu){
    if(arr.size()<stu) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int maxi=accumulate(arr.begin(),arr.end(),0);
    for(int i=low;i<=maxi;i++){
          if(countStu(arr,i)==stu){
            return i;
          }
    }
    return low;
}

int sol2(vector<int> arr,int stu){
    if(arr.size()<stu) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while (low<=high){
        int mid=(low+high)/2;
        
          if(countStu(arr,mid)>stu){
            low=mid+1;
          }
          else{
           high=mid-1;
          }
    }
    return low;
}



int main(){
vector<int> arr = {25, 46, 28, 49, 24};
    int m = 3;
    int ans = sol2(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}