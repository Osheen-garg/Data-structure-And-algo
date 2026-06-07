#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node * reverseList(Node *head){
   Node* prev=nullptr;
   Node* temp=head;
   while(temp!=nullptr){
    Node*front =temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;

   }
   return prev;
}

Node *recursiveReverseList(Node* head){
    if (head == NULL || head->next == NULL)
            return head;

    Node* newhead=recursiveReverseList(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;

    return newhead;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }    
    cout<<endl;
}

int main(){
Node *newNode=new Node(3);
newNode->next=new Node(4);
newNode->next->next=new Node(5);
newNode->next->next->next=new Node(6);
Node* List=recursiveReverseList(newNode);
printList(List);
    return 0;
}