#include<bits/stdc++.h>
using namespace std;

int maxSubarrSum1(vector <int> arr){
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<j;k++ ){
                sum+=arr[k];
            }
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

int maxSubarrSum2(vector <int> arr){
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
      int sum=0;
        for(int j=i;j<n;j++){
                sum+=arr[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

int maxSubarrSum3(vector <int> arr){
    int n=arr.size();
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=arr[i];
      if(sum>maxi){
        maxi=sum;
      }
      if(sum<0){
         sum=0;
      }
    }
    return maxi;
}

int maxSubarrSum4(vector <int> arr){
    int n=arr.size();
    int maxi=INT_MIN;
    int sum=0;
    int start=0;
    int ansstart=-1;
    int ansend=-1;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
       sum+=arr[i];
      if(sum>maxi){
        maxi=sum;
        ansstart=start;
        ansend=i;
      }
      if(sum<0){
         sum=0;
      }
    }

    for(int i=ansstart;i<=ansend;i++){
       cout<<arr[i]<<" ";
    }
    return maxi;
}

int main(){
    vector <int> arr={-2, -3, -7, -2, -10, -4};
    cout<<maxSubarrSum4(arr);
    return 0;
}