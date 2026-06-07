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

Node* sepEvenOdd1(Node* head){
    vector<int> arr;
    Node* temp=head;

    if(head==nullptr) return nullptr;
    if(head->next==nullptr)return head;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp!=nullptr){
         arr.push_back(temp->data);
    }

    temp=head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }

    if(temp!=nullptr){
         arr.push_back(temp->data);
    }

    head=new Node(arr[0]);
    Node* y=head;
   for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
     }
     return head;
}

Node* sepEvenOdd2(Node* head){

    if(head==nullptr) return nullptr;
    if(head->next==nullptr)return head;

    Node* odd=head;
    Node* even=head->next;
    Node*evenHead=even;

    while(even!=nullptr &&even->next!=nullptr){
        odd->next=even->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;

    return head;
}


int main(){
vector<int> arr={2,4,6,7,8,9};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printList(head);
Node*List=sepEvenOdd2(head);
printList(List);
    return 0;
}
