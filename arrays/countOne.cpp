#include<bits/stdc++.h>
using namespace std;

//TC O(n)
int countOne(int arr[],int n){
    int max_count=0,count =0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
           
            count++;
            max_count=max(max_count,count);
        }
        else{
            count =0;
        }
    }
    return max_count;
}
int main(){
    int arr[]={1,1,0,1,1,1,0,1,1,1,1,1,0,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<countOne(arr,n);
    return 0;
}