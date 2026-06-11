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

void printLL(Node * head){
   Node* temp=head;
    while(temp !=nullptr){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}

Node* sol1(Node* head, int k) {
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;
    Node* temp = head;
    int len = 1;

    while(temp->next != nullptr) {
        temp = temp->next;
        len++;
    }
    k = k % len;
    if(k == 0) return head;

    temp->next = head;
    int step = len - k - 1;
    Node* newTail = head;
    while(step--) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
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
printLL(head);
head=sol1(head,3);
cout<<endl;
printLL(head);

    return 0;
}