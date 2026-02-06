 #include<bits/stdc++.h>
using namespace std;

void explainQueue(){
   queue<int> q;
   q.push(2);
   q.push(3);
   q.push(4);
   q.push(5);
   q.emplace(6);
   q.back()+=5;
   cout<<q.back();
      cout<<q.front();
      q.pop();
         cout<<q.back();





}
int main(){
    explainQueue();
    return 0;
}