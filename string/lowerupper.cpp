#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string LtoU(string s){
 string s1="";
 for(char c:s){
    if(c>='A' && c<='Z'){
        s1+=c+32;
    }
    else if(c>='a' && c<='z'){
        s1+=c-32;
    }
    else{
        s1+=c;
    }
 }
 return s1;
}
int main(){
   string s;
   cout<<"Enter the string:";
   cin>>s;
   cout<<LtoU(s);
    return 0;
}