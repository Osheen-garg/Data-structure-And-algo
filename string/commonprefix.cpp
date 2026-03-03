#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string sol(vector <string> s){
  for(int i=0;i<s[0].size();i++){
    char current=s[0][i];
    for(int j=1;j<s.size();j++){
       if(i>=s[j].size()||s[j][i]!=current)
         return s[0].substr(0,i);
    }
  }
  return s[0];

//     if(s.empty()) return "";
//     string ans="";

//     sort(s.begin(),s.end());

//     int minLen=min(s[0].size(),s[s.size()-1].size());

//     for(int i=0;i<=minLen;i++){
//             if(s[0][i]!=s[s.size()-1][i]) break;

//             ans+=s[0][i];
//     }
// return ans;



}


int main(){
    vector<string> s={"flower", "flow", "flight"};

    cout<<sol(s);
    // for(string c: s){
    //     cout<<c<<" ";
    // }
    return 0;
}