#include<bits/stdc++.h>
using namespace std;
int largestNumber(int arr[],int n){
    int max=arr[0];
for(int i=1;i<n;i++){
if(arr[i]>max){
    max=arr[i];
}

}
return max;
}
int main(){
        //int arr[]={2,7,4,6,20,1,14,10,3};
    //int n=sizeof(arr)/sizeof(arr[0]);

   // int num=largestNumber(arr,n);
   // cout<<num;

   vector<int> arr={2,7,4,6,20,1,14,10,3};
   sort(arr.begin(),arr.end());
   cout<<arr[arr.size()-1];
    return 0;

}