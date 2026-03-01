#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sol1(string s1 ,string goal){
    if(s1.size()!=goal.size()) return false;
     s1+=s1;
     int l=goal.size();
     for(int i=0;i<s1.size();i++){
          if(s1.substr(i,l)==goal)
            return true;
     }
     return false;
}

bool sol2(string s1 ,string goal){
    if(s1.size()!=goal.size()) return false;
    return (s1+s1).find(goal)!= string::npos;
   
}

int main(){

  string s1 ="abcde";
  string goal="deabc";
  cout<<sol2(s1,goal);

    return 0;
}