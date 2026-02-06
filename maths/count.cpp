#include<bits/stdc++.h>
using namespace std;
int countDigit(int n){
    int count=0;
    while(n!=0){
        count+=1;
        n/=10;
    }
    return count;
}
int main(){
cout<<countDigit(2);
 return 0;
}