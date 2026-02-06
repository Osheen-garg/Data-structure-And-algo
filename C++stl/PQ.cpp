 #include<bits/stdc++.h>
using namespace std;

void explainPQ(){
   priority_queue<int> q;
   q.push(2);
   q.push(3);
   q.push(4);
   q.push(5);
   q.emplace(6);
 
   cout<<q.top();
     q.pop();
      cout<<q.top();
      priority_queue<int,vector<int>,greater<int>> pq;
       pq.push(3);
   pq.push(4);
   pq.push(5);
   pq.emplace(6);
         cout<<pq.top();





}
int main(){
    explainPQ();
    return 0;
}