#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sol(vector<int> arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=min(ans,arr[mid]);
        }
    }
    return ans;
}
int findMin(vector<int>& nums) {

        // Initialize low and high pointers
        int low = 0, high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {

                low = mid + 1;

            } else {

                high = mid;
            }
        }

        return nums[low];
    }

 
int main(){

        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = sol(nums);
    cout << "Minimum element is " << result << endl;
    return 0;
}