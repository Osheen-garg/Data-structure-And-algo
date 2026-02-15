#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool countBouque(vector<int>arr,int day,int m,int k){
    int count =0;
    int bouque=0;
    for(auto i:arr){
        if(i<=day){
            count++;
            if(count==k){
                bouque++;
                count=0;
            }
        }
        else count=0;
    }
    return bouque>=m;
}

int sol1(vector<int>a, int m,int k){
    long long totalFlower=1LL*m*k;
    if(totalFlower>a.size()) return -1;

    int mini=*min_element(a.begin(),a.end());
    int maxi=*max_element(a.begin(),a.end());

    for(int i=mini;i<=maxi;i++){
        if(countBouque(a,i,m,k)){
            return i;
        }
    }
    return -1;
}

int sol2(vector<int>a,int m,int k){
      long long totalFlower=1LL*m*k;
    if(totalFlower>a.size()) return -1;
    int mini=*min_element(a.begin(),a.end());
    int maxi=*max_element(a.begin(),a.end());
    int low=mini;
    int high=maxi;
    int result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(countBouque(a,mid,m,k)){
            result=mid;
            high=mid-1;
        }else low=mid+1;
    }
    return result;
}

int main(){
  vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;

    int result = sol2(bloomDays, m, k);

    if (result == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << result << "\n";

    return 0;
}