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

void insertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp; 
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


//better
Node* remove_n(Node* head,int n){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    int todel=count-n;
    
    Node* node;
    temp=head;
    if(todel==0){
        node=head;
        head=head->next;
        delete(node);
        return head;
    }
    while(todel!=0){
        node=temp;
        temp=temp->next;
        todel--;
    }
    node->next=node->next->next;
    delete(temp);
    return head;
}

//Optimal:-using slow pointer and fast pointer moving evrytime by one and having 
//difference of n nodes b/w them

Node* remove_n2(Node* head,int n){
    Node* slow=head;
    Node* fast=head;
    int count=n;
    while(n!=0){
        fast=fast->next;
        n--;
    }

    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    return head;
}

int main(){
    Node* node1=new Node(3);
    Node* head =node1;
    insertAtHead(head,4);
    insertAtHead(head,10);
    insertAtHead(head,5);
    // print(head);
    head=remove_n2(head,2);
    print(head);
    
}