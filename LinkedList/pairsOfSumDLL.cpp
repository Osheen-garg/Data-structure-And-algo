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

vector<vector<int>> sol1(Node* head,int sum){
    vector<vector<int>>ans;
    Node* temp1=head;
    while (temp1!=nullptr){
         Node* temp2=temp1->next;
         while (temp2!=nullptr){
             if(temp1->data + temp2->data==sum){
                ans.push_back({temp1->data,temp2->data});
             }
             temp2=temp2->next;
         }
         temp1=temp1->next;
    }
    return ans;
}

vector<vector<int>> sol2(Node* head,int sum){
    vector<vector<int>>ans;
  
    if(head == nullptr) return ans;

    Node* left = head;
    Node* right = head;

    while(right->next != nullptr){
        right = right->next;
    }

    while(left != right && left->back != right){
        int currSum = left->data + right->data;

        if(currSum == sum){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(currSum < sum){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }

    return ans;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);
    cout<<endl;
  vector<vector<int>> ans=sol2(head,5);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
    return 0;
}