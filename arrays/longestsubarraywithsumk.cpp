#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> arr){
    int n=arr.size();
    map <int,int> mpp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
       if(sum==0) maxi=i+1;
       else {
       if(mpp.find(sum)!=mpp.end()){
        maxi=max(maxi,i-mpp[sum]);
       }
       else{
          mpp[sum]=i;
       }
    }
    }
    return maxi;
}

int main(){
     vector <int> A= {9, -3, 3, -1, 6, -5};

  cout << func(A) << endl;


    return 0;
}