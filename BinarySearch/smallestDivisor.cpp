#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int>arr,int limit){
    int maxi=*max_element(arr.begin(),arr.end());
    for(int i=1;i<=maxi;i++){
        int sum=0;
        for(int j=0;j<arr.size();j++){
            sum+=ceil((double)arr[j]/(double)i);
        }
        if(sum<=limit) return i;
    }
    return -1;
}

int sumcal(vector<int>arr,int div){
    int sum=0;
    for(auto i:arr){
          sum+=ceil((double)i/(double)div);
    }
    return sum;
}

int sol2(vector<int>arr,int limit){
    if(arr.size()>limit) return -1;
    int high=*max_element(arr.begin(),arr.end());
    int low=1;
    while(low<=high){
        int mid=(low+high)/2;
        if(sumcal(arr,mid)<=limit){
           high= mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int main(){
      vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = sol2(arr, limit);

    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}