#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int> arr){
int n=arr.size();
int low=0;
int high=n-1;
while (low<high)
{
   int mid=low+((high-low)/2);
   if( arr[mid]>arr[high]){
    low=mid+1;
   }
   else{
    high=mid;
   }

}
return low;
}

int sol2(vector <int> arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int index=-1;
    int mini=INT_MAX;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            high=mid-1;
            if(arr[mid]<mini){
                mini=arr[mid];
                index=mid;
            }
        }
    }
    return index;
}

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = sol2(nums);
    cout << "Number of rotated element is " << result << endl;
    return 0;
}