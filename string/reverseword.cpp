#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
string reverseWords1(string s){
   int i=s.size()-1;
   string result="";

   while(i>=0){
    while(i>=0 && s[i]==' ')
    i--;
    if(i<0) break;

    int j=i;
    while (j>=0 && s[j] !=' ')
        j--;
 

    if(!result.empty())
    result+=" ";
   result +=s.substr(j+1,i-j);
    i=j-1;
    
   }
   return result;
}

void removetrailspace(string &s){
    int n=s.size();
    int i=0,j=0;
    while(i<n && s[i]==' ')
    i++;
    while (i<n){
      if(s[i]!= ' '){
        s[j++]=s[i++];
      }
      else{
        s[j++]=' ';
        while(i<n && s[i]==' ')
            i++;
        }
    }
   if(j>0 && s[j-1] == ' ')
   j--;   
   s.resize(j);
}

string reverseWords2(string s){
    removetrailspace(s);
    reverse(s.begin(),s.end());

    int start=0;
    for(int end=0;end<=s.size();end++){
        if(end==s.size()||s[end]==' '){
            reverse(s.begin()+start,s.begin()+end);
            start=end+1;
        }
    }
    return s;

}
int main(){
     string s = "  hello world  ";
    // removetrailspace(s);
    cout<<reverseWords1(s);
    // cout<<s.size();
    return 0;
}