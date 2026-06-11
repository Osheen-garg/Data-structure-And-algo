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

Node* MiddleNode(Node* head){
    Node * slow=head;
    Node* fast=head->next;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; 


}

Node* Merge(Node* head1,Node* head2){
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

Node* SortLL(Node* head){
     if (head == nullptr || head->next == nullptr) {
            return head;
        }
    Node* middleNode=MiddleNode(head);
    Node * right=middleNode->next;
    middleNode->next=nullptr;
    Node* left=head;
    left=SortLL(left);
    right=SortLL(right);
     return Merge(left,right);
}

int main(){
vector<int> arr={8,4,7,3,6,5,1,2,9};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printList(head);
head=SortLL(head);
printList(head);
    return 0;
}
