#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int expand(string s,int left,int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}
string sol1(string s){
    int start=0;
    int end=0;
    for(int i=0;i<s.size();i++){
        int len1=expand(s,i,i);
        int len2=expand(s,i,i+1);
        int len=max(len1,len2);

        if(len>end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    return s.substr(start,end-start+1);
}



int main(){

    string s="babad";
    cout<<sol1(s);

    return 0;
}