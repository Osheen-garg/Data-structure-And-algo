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
bool palindrome(int n){
  int plNum=reverseN(n);
  if (plNum==n){
    return true;
  }
  else{
    return false;
  }



}
int main(){

cout<<palindrome(3453);



    return 0;
}