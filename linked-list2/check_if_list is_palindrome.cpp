#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* insertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp; 

    return head;
}

void print(Node* &head){
    Node* node=head;
    while(1){
        if(node==0){
            break;
        }
        cout<<node->data;
        node=node->next;
        
    }
}


Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}


//Optimal:- find the middle of the linked list -> reverse the second half then compare the-> first half and second half 
bool isPalindrome(Node *head){
    if(head==NULL || head->next==NULL) return true;

    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* mid=slow;
    Node* slow->next=reverse(slow->next);
    Node* dummy=head;

    while(slow!=NULL) {
        if(dummy->num != slow->num) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}


int main(){

}