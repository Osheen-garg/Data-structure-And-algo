#include<bits/stdc++.h>
using namespace std;
vector<int> twoSumsol1(vector<int>nums,int target ){
    vector <int> ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }

    }
    return {-1,-1};

}
vector<int> twoSumsol2(vector<int>nums,int target ){
    vector <int> ans;
    map<int,int> mpp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int num=nums[i];
        int more=target-num;
        if(mpp.find(more)!=mpp.end()){
            return {mpp[more],i};
        }
        mpp[num]=i;
    }
    return {-1,-1};
}
string twoSumsol3(vector<int>nums,int target ){
    int n=nums.size();
    int left=0;
    int right=n-1;
    while (left<right)
    {
        int sum=nums[left]+nums[right];
        if(sum==target) return "yes";
        else if(sum<target) left++;
        else right--;
    }
    return "No";
    
}


int main(){
   vector <int> arr={2,5,9,6,1,7};
   int target=12;
//    vector <int> ans=twoSumsol2(arr,target);
// for(int i=0;i<2;i++){
//     cout<<ans[i]<<" ";
// }
string ans=twoSumsol3(arr,target);
cout<<ans;
    return 0;
}