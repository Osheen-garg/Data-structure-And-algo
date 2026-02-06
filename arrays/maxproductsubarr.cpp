
#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int> &arr){
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
     
        for(int j=i;j<n;j++){
            int prod=1;
            for(int k=i;k<=j;k++){
              prod*=arr[k];
            }
           maxi=max(maxi,prod);

        }
    }
    return maxi;
}

int sol2(vector<int> &arr){
    int n=arr.size();
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=i;j<n;j++){
         prod*=arr[j];
           maxi=max(maxi,prod);
        }
    }
    return maxi;
}

int sol3(vector<int> &arr){
    int n=arr.size();
    int pre=1;
    int suff=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
       if(pre==0) pre=1;
       if(suff==0) suff=1;
         pre*=arr[i];
         suff*=arr[n-i-1];
         maxi=max(maxi,max(pre,suff));
    }
    return maxi;
}


int main(){

    vector<int> arr={2,4,-2,3,5,-6};
    cout<<sol2(arr);
    return 0;
}
