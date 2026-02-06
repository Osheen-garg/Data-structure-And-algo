#include<bits/stdc++.h>
using namespace std;
int countD(int n){
    int count=0;
    while(n>0){
        count+=1;
        n/=10;
    }
    return count;

}
int powerInt(int digit ,int power){
    int num=1;
      for(int i=1;i<=power;i++){
        num=num*digit;
      }
      return num;
}
bool isArmstrong(int n){
   int power=countD(n);
   int sum=0;
   int num=n;
   while(n>0){
    int digit=n%10;
    sum+=powerInt(digit,power);
    n/=10;
   }
   
    return (sum==num);
}
int main(){
    cout<<isArmstrong(153);
    return 0;
}