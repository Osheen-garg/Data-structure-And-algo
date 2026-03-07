#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sol(string s){
    int maxlen=0;
    int cnt=0;
    for(char c: s){
        if(c=='(') cnt++;
        else if(c==')')cnt--;
        maxlen=max(cnt,maxlen);
    }
    return maxlen;
}

int main(){
 string s="(1+(2*3)+((8)/4))+1";
 cout<<sol(s);
    return 0;
}