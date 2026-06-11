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

Node* sol1(Node* head){
      if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp=head;
    int len=0;
    while (temp!=nullptr)
    {
        len++;
        temp=temp->next;
    }
    int mid=len/2;
    temp=head;
    while(temp!=nullptr){
        mid--;
        if(mid==0){
            Node* deleteNode=temp->next;
            temp->next=temp->next->next;
            delete  deleteNode;
            break;
        }
    
        temp=temp->next;
    }
    return head;
    
}

Node* sol2(Node* head) {
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while(fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}



int main(){
vector<int> arr={2,4,6,7,8,};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printLL(head);
head=sol2(head);
cout<<endl;
printLL(head);


    return 0;
}