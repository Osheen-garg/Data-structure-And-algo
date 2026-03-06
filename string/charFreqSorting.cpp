#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<char> sol(string &s){

    unordered_map<char,int> mpp;

    for(char c:s){
        mpp[c]++;
    }
    vector <char> chars;
    for(auto &c :mpp){
        chars.push_back(c.first);
    }

    sort(chars.begin(),chars.end(),[&](char a,char b){
    if(mpp[a]==mpp[b])
    return a<b;
    return mpp[a]>mpp[b];
    });

 return chars;
}

int main(){
    string s = "banana";
     vector<char> result = sol(s);
      for (char c : result) 
      { cout << c << " "; }


    return 0;
}