#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sol(string s1,string s2){
    if(s1.size()!=s2.size()) return false;
    vector <int> m1(256,0);
    vector<int> m2 (256,0);


    for(int i=0;i<s1.size();i++){
        if(m1[s1[i]]!=m2[s2[i]])  return false;
        m1[s1[i]]=i+1;
        m2[s2[i]]=i+1;
    }
    return true;

}


int main(){
 string s = "paper";
      string t = "tite";

      if (sol(s, t)) {
          cout << "Strings are isomorphic." << endl;
      } else {
          cout << "Strings are not isomorphic." << endl;
      }
    return 0;
}