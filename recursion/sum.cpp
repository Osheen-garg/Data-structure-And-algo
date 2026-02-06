#include<bits/stdc++.h>
using namespace std;
int NnumbersSum(int n){
            if(n==0) return 0;
                return n + NnumbersSum(n-1);
		}
int main(){
       int n;
cout<<"Enter the number:";
cin>>n;
cout<<NnumbersSum(n);
    return 0;
}

