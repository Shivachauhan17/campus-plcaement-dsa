#include<iostream>
// #include<list>
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

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    return 0;
}