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

Node* MiddleSol1(Node* head){
    Node *temp=head;
    int count =0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    int mid=count/2+1;
    temp=head;
    while(temp!=nullptr){
        mid=mid-1;
        if(mid==0) break;
        temp=temp->next;
    }
    return temp;
}

Node* MiddleSol2(Node* head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=nullptr &&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node *newNode=new Node(10);
    newNode->next=new Node(20);
     newNode->next->next=new Node(30);
     newNode->next->next->next=new Node(40);
 newNode->next->next->next->next=new Node(50);
 newNode->next->next->next->next->next=new Node(60);
 Node* middleData=MiddleSol2(newNode);
 cout<<middleData->data;

    return 0;
}