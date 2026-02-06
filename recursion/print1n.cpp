#include<bits/stdc++.h>
using namespace std;
void printNum(int n){
    if(n==0) return;
printNum(n-1);
cout<<n<<" ";
}

int main(){
int n;
cout<<"Enter the number:";
cin>>n;
printNum(n);

    return 0;
}