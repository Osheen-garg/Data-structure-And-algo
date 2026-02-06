 #include<bits/stdc++.h>
using namespace std;

void explainMultiSet(){

multiset<int>ms;
ms.insert(1);
ms.insert(3);
ms.insert(4);


ms.erase(1);
int cnt=ms.count(1);
ms.erase(ms.find(1));


ms.erase(ms.find(1),ms.find(1)+2);




}

int main(){
    return 0;
}