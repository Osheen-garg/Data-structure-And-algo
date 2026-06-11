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

Node* sol2(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;

    while (t1 && t2)
    {
       if(t1->data<=t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
       }
       else{
        temp->next=t2;
            temp=t2;
            t2=t2->next;
       }
    }

    if(t1)temp->next=t1;
    else temp->next=t2;
    return dummyNode->next;
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
Node *head1=new Node(3);
head1->next=new Node(4);
head1->next->next=new Node(5);
head1->next->next->next=new Node(6);
printList(head1);

Node *head2=new Node(1);
head2->next=new Node(1);
head2->next->next=new Node(2);
head2->next->next->next=new Node(7);
printList(head2);

Node* list=sol2(head1,head2);
printList(list);

    return 0;
}