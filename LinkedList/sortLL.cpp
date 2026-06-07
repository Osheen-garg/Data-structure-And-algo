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

Node* sort1(Node* head){
    if(head==nullptr) return nullptr;
Node*temp=head;
int cnt0=0;
int cnt1=0;
int cnt2=0;
while(temp!=nullptr){
    if(temp->data==0) cnt0++;
    else if (temp->data==1)cnt1++;
    else cnt2++;
    temp=temp->next;
}
temp=head;
while (temp!=nullptr)
{
    if(cnt0){ 
        temp->data=0;
        cnt0--;
    }
    else if(cnt1) {
        temp->data=1;
        cnt1--;
    }
    else{ 
        temp->data=2;
        cnt2--;
    }
    temp=temp->next;
}
return head;

}

Node* sort2(Node* head){
Node* zeroDummy=new Node(-1);
Node* oneDummy=new Node(-1);
Node* twoDummy=new Node(-1);

Node* zeros=zeroDummy;
Node* ones=oneDummy;
Node* twos=twoDummy;

Node* temp=head;

while (temp)
{
   if(temp->data==0){
    zeros->next=temp;
    zeros=zeros->next;
   }
   else if(temp->data==1){
    ones->next=temp;
    ones=ones->next;
   }
   else{
    twos->next=temp;
    twos=twos->next;
   }
   temp=temp->next;
}

zeros->next=(oneDummy->next)?oneDummy->next :twoDummy->next;
ones->next=twoDummy->next;
twos->next=nullptr;
head=zeroDummy->next;

delete zeroDummy;
delete oneDummy;
delete twoDummy;
return head;
}

int main(){
vector<int> arr={0,2,1,0,2,2,1,0,1};
Node* head=new Node(arr[0]);
Node* y=head;
for(int i=1;i<arr.size();i++){
    Node* nextNode=new Node(arr[i]);
    y->next=nextNode;
    y=nextNode;
}
printList(head);
Node*List=sort2(head);
printList(List);
    return 0;
}
