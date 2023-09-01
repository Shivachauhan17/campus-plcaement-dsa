#include<iostream>
#include<unordered_set>
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

// Better:- detect cycle using a hashmap -> which stores adresses
bool cycledetect(Node* &head){
    unordered_set<Node*> hashTable;
    while(head!=NULL){
        if(hashTable.find(head)!=hashTable.end()) return true;
        hashTable.insert(head);
        head=head->next;
    }
    return false;
}

//Optimal:-slow and fast pointer -> there are tend to meet at some point if there is a cycle
bool cycledetect2(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        if(fast==slow) return true;
        fast=fast->next->next;
        slow=slow->next;
    }
    return false;
}


int main()
{
    //creating the question
    Node *head=new Node(-4);
    Node* temp=head;
    insertAtHead(head,0);
    Node* temp2=insertAtHead(head,2);
    insertAtHead(head,3);
    temp->next=temp2;
    cout<<cycledetect2(head);
}