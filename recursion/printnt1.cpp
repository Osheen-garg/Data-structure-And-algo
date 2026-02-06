#include<bits/stdc++.h>
using namespace std;
void printNumber(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl; 
    printNumber(n-1);
}
int main(){
      int n;
cout<<"Enter the number:";
cin>>n;
printNumber(n);
    return 0;
}