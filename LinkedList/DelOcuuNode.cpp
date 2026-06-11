#include <iostream>
#include <bits/stdc++.h>
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

Node* delOccurence(Node* head,int val){
  Node* temp=head;
  while(temp!=nullptr){
    if(temp->data==val){
        if(head==temp){
            head=head->next;
        }
        Node*prevNode=temp->back;
        Node* nextNode=temp->next;

        if(prevNode!=nullptr) prevNode->next=nextNode;
        if(nextNode!=nullptr)
        nextNode->back=prevNode;
         
        delete temp;
        temp=nextNode;
    }
    else temp=temp->next;

  }
  return head;
}


int main() {
   
    vector<int> arr = {6,12, 5,6, 8, 7,6, 4};

    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);
cout<<endl;
    head=delOccurence(head,6);
    print(head);

    return 0;
}