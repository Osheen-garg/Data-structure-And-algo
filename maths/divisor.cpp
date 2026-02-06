#include<bits/stdc++.h>
using namespace std;

vector<int> divisor(int n){
    vector <int> div;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            div.push_back(i);
        }
    }
    return div;
}
int main(){
    vector <int> divisors=divisor(12);
    for(auto it=divisors.begin();it!=divisors.end();it++){
        cout<<*(it)<<endl;
    }
    return 0;
}