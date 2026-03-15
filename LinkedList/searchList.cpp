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
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

bool SearchNode(Node* head,int target){
    Node* temp=head;
    while(temp!=nullptr){
       if(temp->data==target) return true;
       temp=temp->next;
    } 
    return false;
}

int main(){
  Node * newNode= new Node(2);
  newNode->next=new Node(5);
  newNode->next->next=new Node(9);
  newNode->next->next->next=new Node(6);

  cout<<SearchNode(newNode,7);

    return 0;
}