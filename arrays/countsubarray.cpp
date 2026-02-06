#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int> &arr,int k){
   int n=arr.size();
   int cnt=0;
   for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        int sum=0;
        for(int k=i;k<=j;k++){
          sum+=arr[k];
        }
        if(sum==k){
            cnt++;
        }
    }
   }
   return cnt;
}

int sol2(vector<int> &arr,int k){
   int n=arr.size();
   int cnt=0;
   for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
         sum+=arr[j];
       
        if(sum==k){
            cnt++;
        }
    }
   }
   return cnt;
}

int sol3(vector<int> &arr,int k){
   int n=arr.size();
   map <int,int> mpp;
   int presum=0 ,cnt=0;
   mpp[0]=1;
   for(int i=0;i<n;i++){
    presum+=arr[i];
    int remove =presum-k;
    cnt+=mpp[remove];
    mpp[presum]+=1;
   }
   return cnt;
}
int main(){
    vector<int>arr={1,3,-3,4,1,1,1,2};
     cout<<sol3(arr,3);
    return 0;
}