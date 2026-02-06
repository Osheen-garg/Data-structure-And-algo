#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    // int ndivisor=0;
    // for(int i=1;i<=n;i++){
    //     if(n%i==0){
    //         ndivisor++;
    //     }
    // }
    // if(ndivisor==2){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    int ndivisor=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ndivisor++;
        }
        if((n/i)!=i){
            ndivisor++;
        }
          
    }
      if(ndivisor==2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    cout<<isPrime(36);
    return 0;
}