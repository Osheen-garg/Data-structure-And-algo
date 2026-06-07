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

Node *recursiveReverseList(Node* head){
    if (head == NULL || head->next == NULL)
            return head;

    Node* newhead=recursiveReverseList(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;

    return newhead;
}

bool checkPalindrome1(Node* head ){
    stack<int> st;
    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=nullptr){
     if(temp->data !=st.top())
      return false;
      st.pop();
      temp=temp->next;
    }

    return true;
    
}

bool checkPalindrome2(Node* head){
    Node* temp=head;
 if (head == NULL || head->next == NULL) return true;

 Node* slow=head;
 Node* fast=head;

 while(fast->next!=nullptr && fast->next->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
 }
Node* newHead=recursiveReverseList(slow->next);
 Node* first=head;
Node* second=newHead;

while(second!=nullptr){
    if(first->data!=second->data) {
        recursiveReverseList(newHead);
        return false;
    }
    first=first->next;
    second=second->next;
}
recursiveReverseList(newHead);
return true;
}


int main(){
vector<int> arr={1,2,3,4,3,2,1};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printList(head);
cout<<checkPalindrome2(head);

    return 0;
}
