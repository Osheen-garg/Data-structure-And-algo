#include<bits/stdc++.h>
using namespace std;
int linearS(vector <int>&arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            return true;
        }
    }
    return false;
}
int sol1(vector <int> &arr){ 
    int longest=1;
    for(int i =0;i<arr.size();i++){
        int cnt=1;
        int x=arr[i];
        while(linearS(arr,x+1)){
            cnt+=1;
            x+=1;
        }
        longest=max(longest,cnt);
    }
   return longest;
}

int sol2(vector<int> &arr){
sort(arr.begin(),arr.end());
int cnt=0;
int longest=1;
int lastSmaller=INT_MIN;
for(int i=0;i<arr.size();i++){
    if(arr[i]-1==lastSmaller){
        cnt+=1;
        lastSmaller=arr[i];
    }
    else if(arr[i]!=lastSmaller){
        cnt=1;
        lastSmaller=arr[i];
    }
    longest=max(longest,cnt);
}
return longest;
}

int sol3(vector <int>&arr){
    int longest=1;
    unordered_set <int> s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }

    for(auto it:s){
        if(s.find(it-1)==s.end()){
            int cnt=1;
            int x=it;
            while(s.find(x+1)!=s.end()){
                cnt+=1;
                x+=1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}
int main(){
     vector <int> arr={100,200,1,3,2,4};
     cout<<sol1(arr);
    return 0;
}