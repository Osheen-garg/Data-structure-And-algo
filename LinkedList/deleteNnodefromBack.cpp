#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
};
void printList(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }    
    cout<<endl;
}

Node* deleteNnode1(Node* head,int n){
   int cnt=0;
   Node* temp=head;
   while (temp){
   cnt++;
   temp=temp->next;
   }
   int res=cnt-n;
   if(cnt==n) return head->next;
   temp=head;
  while(temp!=nullptr){
    res--;
    if(res==0){
        break;
    }
    temp=temp->next;
  }
   Node * delNode=temp->next;
   temp->next=temp->next->next;
   delete delNode;
   
   return head;

}

Node* deleteNnode2(Node* head,int n){
    Node* slow=head;
    Node* fast=head;

    for(int i=0;i<n;i++){
        fast=fast->next;
    }
     if(fast==nullptr) return head->next;
    while (fast->next!=nullptr)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node * delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}

int main(){
vector<int> arr={1,2,3,4,5};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printList(head);
Node*List=deleteNnode2(head,2);
printList(List);
    return 0;
}
