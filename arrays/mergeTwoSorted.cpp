#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &num1,int m,vector<int> &num2,int n){
  
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0){
        if(num1[i]>num2[j]){
            num1[k]=num1[i];
            k--;
            i--;
        }else{
            num1[k]=num2[j];
            k--;
            j--;
        }
    }
    while (j>=0)
    {
        num1[k]=num2[j];
        k--;
        j--;
    }
 
}
int main(){
     vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m=3; int n=3;
    merge(nums1,m, nums2,n);

      for (int num : nums1){
     cout << num << " ";
    }
    return 0;
}