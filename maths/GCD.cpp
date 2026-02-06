#include<bits/stdc++.h>
using namespace std;

int GCD(int n1,int n2){
    for(int i=min(n1,n2);i>0;i--){
        if(n1%i==0 && n2%i==0){
            return i;
        }
    }
    return 1;
}


int main(){

cout<<GCD(6,12);

return 0;    
}
