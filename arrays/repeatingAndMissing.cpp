#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector <int> sol1(vector<int> nums){
    int n=nums.size();
    int repeating=-1;
    int missing =-1;

    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==i){
                count+=1;
            }
            if(count==2) repeating=i;
            else if(count==0) missing=i;

            if (repeating != -1 && missing != -1)
                break;

        }
        
    }
    return {missing,repeating};
}

vector <int> sol2(vector<int> nums){
    int n=nums.size();
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
         hash[nums[i]]++;
    }
    int repeating = -1, missing = -1;

        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                repeating = i;
            } else if (hash[i] == 0) {
                missing = i;
            }

            if (repeating != -1 && missing != -1) {
                break;
            }}
             return {repeating, missing};
}

vector <int> sol3(vector<int> nums){
    int n=nums.size();
    int SumOfN=(n*(n+1))/2;
    int SumOfSqN=(n*(n+1)*(2*n+1))/6;
    int arrSumOfN=0;
    int arrSumOfSqN=0;
    for(int i=0;i<n;i++){
         arrSumOfN+=nums[i];
         arrSumOfSqN+=(nums[i]*nums[i]);
    }
    int val1=SumOfN-arrSumOfN;
    int val2=SumOfSqN-arrSumOfSqN;
    val2=val2/val1;
    int x =(val1+val2)/2;
    int y=val2-x;
    return{x,y};
}
int main(){
        vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    vector<int> result = sol2(nums);
    
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";


    return 0;
}