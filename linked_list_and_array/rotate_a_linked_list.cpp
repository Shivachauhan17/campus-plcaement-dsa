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

Node* rotate(Node* head,int k){
    int list_len=0;
    Node* temp=head;
    Node* lastNode;
    while(temp!=NULL){
        list_len+=1;
        lastNode=temp;
        temp=temp->next;
    }
    k=k%list_len;
    temp=head;
    int to_point=list_len-k;
    Node* prev;
    while(to_point!=0){
        prev=temp;
        temp=temp->next;
        to_point-=1;
    }
    prev->next=NULL;
    lastNode->next=head;
    head=temp;

    return head;

}


int main(){
    Node* head=new Node(5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    Node* ans=rotate(head,2);
    print(ans);
    return 0;
}