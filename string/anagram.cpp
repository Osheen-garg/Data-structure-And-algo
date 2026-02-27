#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sol1(string s1,string s2){
    if(s1.size()!=s2.size()) return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}

bool sol2(string s1,string s2){
     if(s1.length() != s2.length())
        return false;
    
    vector<int> freq(26,0);
    for(char c: s1)
    freq[c-'a']++;
    for(char c: s2)
    freq[c-'a']--;
     for(int i = 0; i < 26; i++)
        if(freq[i] != 0)
            return false;

    return true;
}

int main(){
    string s1="osheen";
    string s2="neehso";
    cout<<sol2(s1,s2);

    return 0;
}