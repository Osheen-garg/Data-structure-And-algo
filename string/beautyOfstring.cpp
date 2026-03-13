#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol(string s){
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> freq;
        for(int j=i;j<n;j++){
            freq[s[j]]++;
            
            int maxi=INT_MIN;
            int mini=INT_MAX;

            for(auto c:freq){
                maxi=max(maxi,c.second);
                mini=min(mini,c.second);
            }
            sum+=(maxi-mini);
        }
    }
    return sum;
}

int main(){
string s="aabcbaa";
cout<<sol(s);
    return 0;
}