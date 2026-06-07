#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

void printLL(Node * head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* insertAtStart(Node *head,int val){
     Node * newNode=new Node(val);
     if(head==nullptr) return newNode;
     head->back=newNode;
     newNode->next=head;
     head=newNode;

     return head;
}

Node* insertAtEnd(Node * head,int val){
     Node * newNode=new Node(val);
     if(head==nullptr) return newNode;
     Node* temp=head;
     while(temp->next!=nullptr){
        temp=temp->next;
     }
     temp->next=newNode;
     newNode->back=temp;
      return head;
}

Node* insertAtPos(Node* head,int val,int pos){
      Node * newNode=new Node(val);
     if(pos==1) return insertAtStart(head,val);
     Node* temp=head;
    int cnt=1;
    while(cnt<pos && temp!= nullptr){
             cnt++;
             temp=temp->next;
    }
     if(temp == nullptr){
        return head;
    }

    Node* prev=temp->back;
    temp->back=newNode;
    prev->next=newNode;
    newNode->back=prev;
    newNode->next=temp;

    return head;

}

Node* deleteAtStart(Node* head){
   Node* temp=head;

   if(head==nullptr|| head->next==nullptr){
          delete head;
          return nullptr;
   }
   head=head->next;
   head->back=nullptr;
   temp->next=nullptr;
   delete temp;
    
   return head;


}

Node* deleteAtEnd(Node* head){
    Node* temp=head;

   if(head==nullptr|| head->next==nullptr){
          delete head;
          return nullptr;
   }

   while (temp->next->next!=nullptr)
   {
        temp=temp->next;
   }
   Node* curr=temp->next;
   temp->next=nullptr;
   curr->back=nullptr;

   return head;
   
}

Node* deleteAtPos(Node* head,int pos){
    if(pos==1) return deleteAtStart(head);
    int cnt=1;
    Node* temp=head;
    while (cnt<pos && temp!=nullptr)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp==nullptr) return head;
    Node*curr=temp; 
    Node* front=temp->next;
    Node* prev=temp->back;
    prev->next=front;
    front->back=prev;
    delete curr;

    return head;
    
}

int main(){
 vector <int> arr={5,9,8,3,4,1,2};
  Node * head=new Node(arr[0]);
Node * y=head;
  for(int i=1;i<arr.size();i++){
        Node* nextNode=new Node(arr[i]);
        y->next=nextNode;
        nextNode->back=y;
        y=y->next;
  }

head=insertAtStart(head,10);  
head=insertAtEnd(head,20);
head=insertAtPos(head,60,4);
head=deleteAtStart(head);
head=deleteAtEnd(head);
head=deleteAtPos(head,3);
printLL(head);

    return 0;
}