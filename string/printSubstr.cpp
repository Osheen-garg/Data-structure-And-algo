#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> sol1(string s){
    vector<string> result;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            result.push_back(s.substr(i,j-i+1));
        }
    }
    return result;
}

vector<string> sol2(string s){
     vector<string> result;

     for(int i=0;i<s.size();i++){
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
              result.push_back(temp);
        }
     }
     return result;
}

int main(){
    string s="abc";
       vector<string> ans=sol2(s);

       for(auto s:ans){
        cout<<s<<" ";
       }


    return 0;
}