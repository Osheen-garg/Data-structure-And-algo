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

bool sol1(Node* head){
    unordered_set<Node*> st;
    Node* temp=head;
    while(temp!=nullptr){
      if(st.find(temp)!=st.end()) return true;  
        st.insert(temp);
        temp=temp->next;
    }
    return false;
}

bool sol2(Node* head){
    Node*slow=head;
    Node*fast=head;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
        
    }
    return false;

}

int main(){
  Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;
// printList(head);
cout<<sol2(head);

    return 0;
}
