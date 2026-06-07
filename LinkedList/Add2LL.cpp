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

Node* addList(Node* h1,Node* h2){
    Node* dummuNode=new Node(-1);
    Node* curr=dummuNode;
    Node* temp1=h1;
    Node*temp2=h2;
    int carry=0;
    while (temp1!=nullptr ||temp2!=nullptr)
    {
        int sum=carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;
        Node* newNode=new Node(sum%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    
    if(carry){
        Node * newNode=new Node(carry);
        curr->next=newNode;
    }
    return dummuNode->next;
}

int main(){
    return 0;
}