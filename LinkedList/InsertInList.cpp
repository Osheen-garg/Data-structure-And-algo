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

Node* insertAtStart(Node* head,int newData){
    Node* newNode=new Node(newData);
    newNode->next=head;
    head=newNode;
    return head;
}

Node* insertAtLast(Node* head,int newData){
    Node* newNode=new Node(newData);
    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
    
}

Node* insertAtSpecific(Node* head ,int val,int pos){
      Node* newNode=new Node(val);
       Node *temp=head;
       if(pos==1){
      return insertAtStart(head,val);
       }
       for(int i=1;i<pos-1 && temp!=nullptr;i++){
        temp=temp->next;
       }
       if (temp == NULL) {
            cout << "Position out of range\n";
            return NULL;
       }
       newNode->next=temp->next;
       temp->next=newNode;
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

head=insertAtStart(head,1);
head=insertAtLast(head,40);
head=insertAtSpecific(head,30,3);
head=insertAtSpecific(head,20,1);
printList(head);
    return 0;
}