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


Node* add(Node* l1,Node* l2){
    Node* dummy;
    Node* temp;
    int carry=0;
    while((l1 != NULL || l2 != NULL) || carry){
        int sum=0;
        if(l1!=NULL)
        sum+=l1->data;
        l1=l1->next;

        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* node= new Node(sum%10);
        temp->next=node;
        temp=temp->next;
        
            }
            return dummy->next;
}

int main(){
    return 0;
}