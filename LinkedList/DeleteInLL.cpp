#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* next;
    Node* back; 

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* DeleteAtEnd(Node* head){
    if(head==nullptr) return NULL;
    else if(head->next==nullptr) {
     delete head;
     return NULL;}
     Node *temp=head;
     while(temp->next!=nullptr){
        temp=temp->next;
     }
     temp->back->next=nullptr;
     delete temp;
     return head;
}

Node* DeleteAtStart(Node* head){
     if(head==nullptr) return NULL;
    else if(head->next==nullptr) {
     delete head;
     return NULL;}
     Node *temp=head;
    head=head->next;
    head->back=nullptr;
    delete temp;
    return head;
}

Node* DeleteAtSpecificPos(Node* head,int pos){
    if(head==nullptr) return NULL;
    else if(head->next==nullptr) {
     delete head;
     return NULL;}
    Node *temp=head;
     for(int i=1;i<pos && temp!=nullptr;i++){
        temp=temp->next;  
     }
     if(temp==nullptr) {
        cout<<"Postion is out of range.";
     }
       if(temp->back != NULL)
        temp->back->next = temp->next;

    if(temp->next != NULL)
        temp->next->back = temp->back;

    delete temp;

    return head;


}
Node* convertArr2DLL(vector<int> arr) {
   
    Node* head = new Node(arr[0]);
    Node* prev = head; 
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        prev = temp; 
    }
    return head;  
}
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;          
    }
}

int main(){
vector<int> arr = {12, 5, 8, 7,9, 4,3};

    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);
    cout<<endl;
    head=DeleteAtEnd(head);
    print(head);
     cout<<endl;
    head=DeleteAtStart(head);
    print(head);
     cout<<endl;
    head=DeleteAtSpecificPos(head,3);
    print(head);
     cout<<endl;

    
    return 0;
}