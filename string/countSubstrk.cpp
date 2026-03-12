#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Atmostk(string s,int k){
    int count =0;
    int left=0;
    unordered_map<char,int> freq;
for(int right=0;right<s.size();right++){
    freq[s[right]]++;
    while(k<freq.size()){
        freq[s[left]]--;
        if(freq[s[left]]==0) freq.erase(s[left]);
        left++;
    }
    count+=right-left+1;
}
return count;
}

int sol1(string s,int k){
    return Atmostk(s,k)-Atmostk(s,k-1);
}

int main(){
string s = "pqpqs";
    int k = 2;
    cout << "Count: " << sol1(s, k) << endl;

    return 0;
}