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
Node * reverseList(Node *head){
   Node* prev=nullptr;
   Node* temp=head;
   while(temp!=nullptr){
    Node*front =temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;

   }
   return prev;
}

Node* getKthNode(Node*temp,int k){
    k-=1;
    while (temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
    
}

Node* sol1(Node* head, int k) {
Node* temp=head;
Node* prevLast=NULL;
while (temp!=nullptr)
{
    Node* kThNode=getKthNode(temp,k);
    if(kThNode==nullptr){
        if(prevLast) prevLast->next=temp;
        break;
    }

    Node* nextNode=kThNode->next;
    kThNode->next=nullptr;
    reverseList(temp);
    if(temp==head){
        head=kThNode;
    }else{
        prevLast->next=kThNode;
    }
    prevLast=temp;
    temp=nextNode;
}
return head;
}

int main(){
vector<int> arr={2,4,6,7,8,9,10};
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