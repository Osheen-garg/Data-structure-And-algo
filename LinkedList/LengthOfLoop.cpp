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

int sol1(Node* head){
    unordered_map<Node*,int> st;
    int timer=1;
    Node* temp=head;
    while(temp!=nullptr){
      if(st.find(temp)!=st.end()) return timer-st[temp];  
        st[temp]=timer;
        temp=temp->next;
        timer++;
    }
    return 0;
}

int cntLen(Node* slow){
int cnt=1;
Node*temp=slow;
while(slow!=temp->next){
    cnt++;
 temp=temp->next;
}
return cnt;

}

int sol2(Node* head){
    Node*slow=head;
    Node*fast=head;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return cntLen(slow);
      
    }
    return 0;

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

    fifth->next = second;
// printList(head);
cout<<sol1(head);

    return 0;
}
