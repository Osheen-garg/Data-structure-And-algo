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

Node* sol1(Node* head){
  Node* temp=head;
  while (temp!=nullptr && temp->next!=nullptr){
    Node* nextNode=temp->next;
    while (nextNode!=nullptr && nextNode->data==temp->data){
        Node* duplicate=nextNode;
        nextNode=nextNode->next;
        delete duplicate;
    }
    temp->next=nextNode;
   if(nextNode!=nullptr) nextNode->back=temp;
    temp=temp->next;

  }
  return head;
  
}

int main(){
    vector<int> arr = {1,1,1,1,2,2,3,4,4,4,5,5,6};

    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);
  Node*list=sol1(head);
  cout<<endl;
  print(head);
    return 0;
}