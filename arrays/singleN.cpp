#include<bits/stdc++.h>
using namespace std;
//TC O(n*n)
int singleCount(int arr[],int n){
int count;
for(int i=0;i<n;i++){
    count=0;
    for(int j=0;j<n;j++){
        if(arr[i]==arr[j]){
            count ++;
        }
    }
    if(count==1) return arr[i];
}
}
//TC O(3n)
//SC O(maxi+1)
int singleN(int arr[],int n){
  int maxi= arr[0];
  for(int i=0;i<n;i++){
maxi=max(maxi,arr[i]);
  }
   vector <int> hash(maxi+1,0);
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[arr[i]]==1)
            return arr[i];
        }
}
//TC O(n+m)
//SC O(m)
int singleMap(int arr[],int n){
    map <int ,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second==1)
        return it.first;
    }
    return -1;
}
//TC O(n)
int singleXor(int arr[],int n){
    int xor1=0;
   for(int i=0;i<n;i++){
    xor1=xor1^arr[i];
   }
   return xor1;
}
int main(){
    int arr[]={1,2,1,2,3,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
   cout<<singleXor(arr,n);
            return 0;

}