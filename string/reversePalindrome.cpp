#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void reverseString(string &s){
  int len=s.size();
    int i=0;
    int j=len-1;
    // cout<<s;
   
    while(i<=j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}

bool palindrome( string &s){
    string s1=s;
      reverseString(s);

      if(s1==s) return true;
      else return false;
}

int main(){


    string s="MAAM";
    reverseString(s);
    cout<<s<<endl;
    cout<<palindrome(s);

    return 0;
}





// Print all substrings

