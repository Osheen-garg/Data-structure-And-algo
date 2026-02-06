#include<bits/stdc++.h>
using namespace std;
int longestsubarraysol1(vector <int> nums,long long k){
    int len=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            long long sum=0;
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
            if(sum==k){
                    len=max(len,j-i+1);
                }
        }
    }
    return len;
}
int longestsubarraysol2(vector <int> nums,long long k){
    int len=0;
    for(int i=0;i<nums.size();i++){
        long long sum=0;
        for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k){
                    len=max(len,j-i+1);
                }
        }
        
    }
    return len;
}
int longestsubarraysol3(vector<int> nums,long long k){
int right=0;
int left=0;
int maxlength=0;
long long sum=nums[0];
int n=nums.size();
while(right<n){
    while (left<=right && sum>k) 
    {
        sum-=nums[left];
        left++;
    }
    if(sum==k){
        maxlength=max(maxlength,right-left+1);
    }
    right++;
    if(right<n){
        sum+=nums[right];
    }
    
}
return maxlength;
}

int longestsubarraysol4(vector <int> nums,int k){
   int n=nums.size();
   int maxlenth=0;
   int sum=0;
   map <int,int> preSumMap;
   for(int i=0;i<n;i++){
    sum+=nums[i];
    if(sum==k){
        maxlenth=max(maxlenth,i+1);
    }
    int rem=sum-k;
    if(preSumMap.find(rem)!=preSumMap.end()){
        int len=i-preSumMap[rem];
        maxlenth=max(maxlenth,len);
    }

    if(preSumMap.find(sum)==preSumMap.end()){
        preSumMap[sum]=i;
    }

   }
   return maxlenth;
}

int main(){
    vector <int> nums={3,5,2,1,3,1,1,1,7,2};
    cout<<longestsubarraysol4(nums,3);
    return 0;
}