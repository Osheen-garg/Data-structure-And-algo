#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol1(vector<int> arr,int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            k++;
        }
        else break;
    }
    return k;
}


int sol2(vector<int>arr,int k){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k) low=mid+1;
        else high=mid-1;
    }
    return k+high+1;
}
int main(){
        vector<int> vec = {1,2,3,4,6, 7, 8, 10};  
    int k = 2;                       
    int ans = sol2(vec, k);  

    cout << "The missing number is: " << ans << "\n";  // Output the result
    return 0;


}