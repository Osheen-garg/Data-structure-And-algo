#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxElementInRow(vector<vector<int>> &arr,int col){
    int index=-1;
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i][col]>maxi){
            maxi=arr[i][col];
            index=i;
        }
    }
    return index;
}


vector<int> sol(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    int low=0;
    int high=m-1;
    while (low<=high){
        int mid=(low+high)/2;
        int row=maxElementInRow(arr,mid);
        int left=mid-1>=0?arr[row][mid-1]:INT_MIN;
        int right=mid+1<m?arr[row][mid+1]:INT_MIN;

        if(arr[row][mid]>left && arr[row][mid]>right)
                return {row,mid};
        else if (arr[row][mid]<left) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
    

}


int main(){
    vector<vector<int>> mat = {
          {4, 2, 5, 1, 4, 5},
          {2, 9, 3, 2, 3, 2},
          {1, 7, 6, 0, 1, 3},
          {3, 6, 2, 3, 7, 2}
      };
  
      
      vector<int> peak =sol(mat);
      cout << "The row of peak element is " << peak[0]
           << " and column of the peak element is " << peak[1] << endl;
  

    return 0;
}

