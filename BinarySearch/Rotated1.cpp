#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int RotatedBn(vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=low+((high-low)/2);

        if(arr[mid]==target){
            return mid;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && arr[mid]>target) high=mid-1;
        
        else low=mid+1;
        }
        else{
            if(arr[mid]<target && arr[high]>=target){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return -1;
    
}

bool RotatedBn1(vector<int> arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=low+((high-low)/2);

        if(arr[mid]==target){
            return true;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            high--;
            low++;
            continue;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && arr[mid]>target) high=mid-1;
        
        else low=mid+1;
        }
        else{
            if(arr[mid]<target && arr[high]>=target){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return false;
    
}


int main(){
 vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = RotatedBn(nums, target);

    cout << result << endl;

    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 2;
    bool ans = RotatedBn1(arr, k);
    if (ans)
        cout << "Target is present in the array.\n";
    else
        cout << "Target is not present.\n";


    return 0;
}
