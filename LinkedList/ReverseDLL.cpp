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

Node* reverse1(Node* head){
    Node* temp=head;
    stack <int>st;
while(temp!=nullptr){
    st.push(temp->data);
    temp=temp->next;
}
temp=head;
while(temp!=nullptr){
    temp->data=st.top();
    st.pop();
    temp=temp->next;
}
return head;}

Node* reverse2(Node* head){
      if (head == nullptr || head->next == nullptr) return head;
    Node *current =head;
    while(current!=nullptr){
        Node * temp=current->next;
        current->next=current->back;
        current->back=temp;
       current=current->back;}
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
    head=reverse2(head);
 print(head);
    cout<<endl;
    return 0;
}