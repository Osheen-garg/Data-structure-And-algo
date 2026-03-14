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

Node* insertAtHead(Node* head,int newData){
    Node* newNode=new Node(newData,head);
    return newNode;
}

void printList(Node* head){
    int count =0;
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    cout<<"\ncount="<<count;
    cout<<endl;
}

int main(){
Node* head=new Node(2);
head->next=new Node(3);
printList(head);

head=insertAtHead(head,1);
printList(head);
    return 0;
}