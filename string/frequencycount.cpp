#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 



int main(){
    string s;
    cout<<"Enter the String:";
    cin>>s;
    vector<int> freq(26,0);

  for(char c:s){
    if(isalpha(c)){
        c=tolower(c);
    freq[c-'a']++;}
  }
  for(int i=0;i<26;i++){
    if(freq[i]==1)
    cout<<char(i+'a')<<"->"<<freq[i]<<endl;
  }


    return 0;
}