#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return true;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

bool sol1(vector<vector<int>> matrix, int target){
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        if(matrix[i][0]<= target && target <=matrix[i][m-1]){
            return binarySearch(matrix[i],target);
        }
    }

    return false;
}

bool sol2(vector<vector<int>> matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    int high=n*m-1;
    int low=0;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}
int main(){
vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    if (sol2(matrix, 8))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}