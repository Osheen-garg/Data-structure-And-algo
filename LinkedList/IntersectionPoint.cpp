#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool sol1(Node* head1, Node* head2){
    Node* temp1 = head1;

    while(temp1 != nullptr){
        Node* temp2 = head2;

        while(temp2 != nullptr){
            if(temp1 == temp2){
                cout << "Intersection Node Value: "
                     << temp1->data << endl;
                return true;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return false;
}

bool sol2(Node* head1,Node* head2){
    unordered_set <Node*> st;
    while (head1!=nullptr){
        st.insert(head1);
        head1=head1->next;
    }
    while (head2!=nullptr){
        if(st.find(head2)!=st.end()){ 
            cout<<head2->data<<endl;
            return true;}
        head2=head2->next;
    }
    return false;
    
}

int getDifference(Node* head1,Node* head2){
 int len1=0;
 int len2=0;
 while(head1!=nullptr|| head2!=nullptr){
    if(head1!=nullptr){
        len1++;
        head1=head1->next;
    }
    if(head2!=nullptr){
        len2++;
        head2=head2->next;
    }

    return len1-len2;
 }

}

bool sol3(Node* head1,Node* head2){
 int diff=getDifference(head1,head2);
 if(diff<0)
    while(diff++!=0) head2=head2->next;
 else  
   while (diff--!=0) head1=head1->next;

   while (head1!=nullptr)
   {
     if (head1 == head2){
        cout<<head1->data<<endl;
        return true;

     }
        head2 = head2->next;
        head1 = head1->next;
   }
   return false;

}

bool sol4(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=temp2){
        temp1=temp1==NULL?head2:temp1->next;

        temp2=temp2==NULL?head1:temp2->next;
    }
    if(temp1) return true;
    return false;
}

int main(){

    // Common part
    Node* common = new Node(3);
    common->next = new Node(4);
    common->next->next = new Node(5);

    // First list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = common;

    // Second list: 9 -> 8 -> 3 -> 4 -> 5
    Node* head2 = new Node(9);
    head2->next = new Node(8);
    head2->next->next = common;

    printList(head1);
    printList(head2);

    bool ans = sol4(head1, head2);

    if(ans)
        cout << "Lists Intersect" << endl;
    else
        cout << "Lists Do Not Intersect" << endl;

    return 0;
}