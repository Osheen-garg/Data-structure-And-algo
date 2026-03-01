#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkdigit(string s){
  for(char c:s){
    if(c>='0' &&c<='9')
    return true;
  }
  return false;
}

int main(){
    string s="osheen124";
    cout<<checkdigit(s);
    return 0;
}