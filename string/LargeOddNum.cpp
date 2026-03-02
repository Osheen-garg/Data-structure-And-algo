#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string sol1(string s){
    int indx=-1;
    int i;
   
   
    for(int i=s.size()-1;i>=0;i--){
        int c=s[i]-'0';
        if(c%2!=0) {
            indx=i;
            break;
        }
    }
      i=0;
     while( i<=indx && s[i]=='0')  i++;
    
    if(indx==-1) return "";
    return s.substr(i,indx-i+1);
}

int main(){
    string s="0003489822";
    cout<<sol1(s);
    return 0;
}