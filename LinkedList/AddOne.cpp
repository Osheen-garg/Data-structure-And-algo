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

Node* iterativeReverse(Node* head){
    if(head==nullptr) return nullptr;
    if(head->next==nullptr) return head;
    Node* temp=head;
    Node* prev=nullptr;

    while( temp){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;
}

Node* addOne1(Node* head){
    if(head == nullptr) return nullptr;

    head = iterativeReverse(head);

    Node* temp = head;
    int carry = 1;

    while(temp != nullptr){
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        if(carry == 0) break;

        if(temp->next == nullptr){
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    return iterativeReverse(head);
}

int addOneUntil(Node* head){
    if(head==nullptr) return 1;
    int carry=addOneUntil(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}

Node* addOne2(Node* head){
    int carry =addOneUntil(head);
    if (carry){
        Node* newNode=new Node(carry);
        newNode->next=head;
        head=newNode;
    }
    return head;
}
int main(){
vector<int> arr={9,9,9,8};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printList(head);
Node* List=addOne2(head);
printList(List);
    return 0;
}
