#include<bits/stdc++.h>
using namespace std;
void printName(int n,int i){
if(i>n) return;
cout<<i<<endl;
 printName(n,i+1);

}
int main(){
    int n,i=1;
cout<<"Enter the number:";
cin>>n;
printName(n,i);
    return 0;
}