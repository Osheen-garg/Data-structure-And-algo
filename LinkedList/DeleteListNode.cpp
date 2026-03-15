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

Node* DeleteNode(Node *head){
    if(head->next==nullptr ||head==nullptr) {
    delete head;
    return nullptr;
    }
   
    Node *temp=head;
    while (temp->next->next!=nullptr)
    {
      temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;

    return head;  
} 

Node * DeletePos(Node *head ,int pos){
     if(head->next==nullptr ||head==nullptr) {
    delete head;
    return nullptr;
    }
    else if(pos==1){
       Node *temp=head;
       head=head->next;
       delete temp;
       return head;
    }
    Node *temp=head;
    for(int i=1;i<pos-1 &&temp->next!=nullptr; i++){
        temp=temp->next;
        if(temp->next==nullptr){
            cout<<"Position is out of range";
        }
    }
    Node *del =temp->next;
    temp->next=del->next;
    delete del;
    return head;
}

int main(){
  Node * newNode= new Node(2);
  newNode->next=new Node(5);
  newNode->next->next=new Node(9);
  newNode->next->next->next=new Node(6);
//   newNode=DeleteNode(newNode);
newNode=DeletePos(newNode,3);
   Node* temp = newNode;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}