#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int len(string s){
    int count=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] != ' ')
        count++;
        else if(count>0) break;
    }
    return count;
}

 void removeSpace(string &s){
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        else{
            s[j++]=s[i];
        }
    }
    s.resize(j);
}


int main(){
string s="osheen Garg programming";

removeSpace(s);
cout<<s;
    return 0;
}