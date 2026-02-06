#include<bits/stdc++.h>
using namespace std;
int reverseN(int n){
    int revNum=0;
    while(n>0){
        int ldigit=n%10;
        
        revNum=(revNum*10)+ldigit;
        n=n/10;
    }
    return revNum;
}
int main(){

cout<<reverseN(4354);
    return 0;
}