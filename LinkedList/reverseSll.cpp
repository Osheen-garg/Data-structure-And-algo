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
    Node* prev=NULL;
    Node* curr=head;
    Node* next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
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
Node* List=reverseList(newNode);
printList(List);
    return 0;
}