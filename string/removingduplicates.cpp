#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removedup(string s){
    vector<int> freq(26,0);
    string s1="";
    for( char c: s){
        if(isalpha(c)){
            c=tolower(c);
        freq[c-'a']++;
      if(freq[c-'a']==1){
        s1+=c;
      }
           
        }
    }
    return s1;
}
string Eremovedup(string s){
    vector<bool> freq(26,false);
    string s1="";
    for( int i=s.size()-1;i>=0;i--){
        if(isalpha(s[i])){
            s[i]=tolower(s[i]);
      if(!freq[s[i]-'a']){
        s1+=s[i];
        freq[s[i]-'a']=true;
      }
           
        }}
        reverse(s1.begin(),s1.end());
    
    return s1;
}

int main(){
    string s;
    cout<<"Enter the String:";
    cin>>s;
    cout<<Eremovedup(s);
    return 0;
}