#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string sol(string s){
    string ans="";
    int length=0;
   for(char c:s){
    if(c=='('){
        if(length>0)
        ans+=c;
        length++;
    }
    else if(c==')'){
        length--;                                                                                     
        if(length>0)
        ans+=c;
    }
   }
    return ans;
}

int main(){
  string s="(())(())";
cout<<sol(s);
    return 0;
}
