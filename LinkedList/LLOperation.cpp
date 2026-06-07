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

int lengthLL(Node * head){
   Node* temp=head;
   int cnt=0;
    while(temp !=nullptr){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int searchLL(Node *head,int val){
     Node* temp=head;
     int cnt=0;
    while(temp !=nullptr){
        cnt++;
        if(temp->data==val) return cnt;
        temp=temp->next;
    }
    return -1;
}

Node* insertAtStart(Node* head,int val){
    Node * newNode=new Node (val);
    newNode->next=head;
    head=newNode;
    return head;

}

Node* insertAtEnd(Node *head,int val){

     Node * newNode=new Node (val);
     if(head == nullptr)
        return newNode;
        Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
     return head;

}

Node* insertAtPos(Node* head,int val,int pos){
     Node * newNode=new Node (val);
     if(head == nullptr) return newNode;
       if(pos == 1){
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int cnt = 1;

    while(temp != nullptr && cnt < pos - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp == nullptr){
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;

}

Node* deleteAtStart(Node* head){
 if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* deleteAtEnd(Node* head){
     if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

    Node *temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node *curr=temp->next;
    temp->next=nullptr;
    delete curr;
    return head;
}

Node* deleteAtPos(Node * head,int pos){
    if(head == nullptr)
        return head;
 if(pos==1){
  return deleteAtStart(head);
 }

 Node *temp=head;
 int cnt=1;
 while(temp->next!=nullptr && cnt<pos-1){
    temp=temp->next;
    cnt++;
 }
  if(temp == nullptr|| temp->next == nullptr){
        return head;
  }

  Node * deleteNode=temp->next;
  temp->next=temp->next->next;
  delete deleteNode;
  return head;
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

head=insertAtStart(head,10);
head=insertAtEnd(head,12);
head=insertAtPos(head,24,4);
head=deleteAtStart(head);
head=deleteAtEnd(head);
head=deleteAtPos(head,4);
printLL(head);
int len=lengthLL(head);
cout<<endl;
cout<<len;
cout<<endl;
cout<<searchLL(head,24);

    return 0;
}