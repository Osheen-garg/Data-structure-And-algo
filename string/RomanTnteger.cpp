#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int value (char c){
    switch (c)
    {
    case 'I':
    return 1;
    case 'V':
    return 5;
    case 'X':
    return 10;
    case 'L':
    return 50;
    case 'C':
    return 100;
    case 'D':
    return 500;
    case 'M':
    return 1000;
}
}
int sol(string s){
    int ans=0;
    unordered_map <char,int> RomanVal={
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };
    for(int i=0;i<s.size();i++){
        if(s.size()>i+1 && RomanVal[s[i]]<RomanVal[s[i+1]]){
            ans-=RomanVal[s[i]];
        }
        else{
            ans+=RomanVal[s[i]];
        }
    }
    return ans;

}


int main(){
string s = "XXIV"; 
    int result = sol(s);
    
    // Print the result
    cout << "Integer value: " << result << endl;
    return 0;
}

//integer to roman