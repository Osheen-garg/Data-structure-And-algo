#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 vector<int> sol1(vector<int> arr){
    vector<int> ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(ans.size()==0||ans[0]!=arr[i]){
            int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt>n/3){
                ans.push_back(arr[i]);
            }
    }
    if(ans.size()==2) break;
    }
    return ans;

 }

 vector<int> sol2(vector<int> arr){
    vector <int> ans;
    map<int,int>mpp;
    int n=arr.size();
    int mini=(int)(n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini){
            ans.push_back(arr[i]);
        }
        if(arr.size()==2) break;
    }
    sort(arr.begin(),arr.end());
    return ans;
 }

vector<int> sol3(vector<int> arr){
    int cnt1=0,cnt2=0,el1=INT_MIN,el2=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=el2){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1){
             cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1) cnt1++;
        else if(arr[i]==el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        } }
       cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
           if(el1==arr[i])cnt1++;
           if(el2==arr[i])cnt2++;
        }
        vector<int> ans;
        int mini=(int)(n/3)+1;
        if(cnt1>=mini) ans.push_back(el1);
        if(cnt2>=mini) ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
}
 int main(){
    vector<int> arr={2,5,2,2,8,5,8,8};
    vector<int> ans=sol3(arr);
    for(int i=0;i<2;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
