#include<iostream>
#include<unordered_map>
using namespace std;


class Node {
    public:
        int val;
        Node* next;
        Node* random;
        Node(int value) {
            val = value;
            next = NULL;
            random = NULL;
        }
};

//Brute Force:- store a copy of every Node in hashmap-> adresses as their keys-> so that they can fetch the temp and random pointer
//from the original linked-list 

Node* copyRandomList(Node* head){
    unordered_map<Node*,Node*> hashmap;
    Node* temp=head;

    //inserting deep node of every node in the hashmap;
    while(temp!=NULL){
        Node* newNode=new Node(temp->val);
        hashmap[temp]=newNode;
        temp=temp->next;
        cout<<temp;
    }
    Node* t=head;

    //link the next and random pointer as original linked list
    while( t!=NULL){
        Node* node = hashmap[t];
        node->next = (t->next != NULL) ? hashmap[t->next]:NULL;
        node->random = (t->random != NULL) ? hashmap[t->random]:NULL;
        t = t->next;
    }
    return hashmap[head];
}



void printList(Node* head) {
    while(head != NULL) {
        cout<<head->val<<':';
        head->next != NULL ? cout<<head->next->val:cout<<"NULL";
        head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
        cout<<endl;
        head = head->next;
    }
}

//Optimal:- for exp-> create thr copy of first node -> point node's next to copy -> copy's next to the  ->second node 
//original:2->3   :: new  2->2'->3

Node* copyRandomList2(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* newNode=new Node(temp->val);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }

    Node* itr = head;
    while(itr != NULL) {
        if(itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }

    Node* dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node* fast;
    while(itr != NULL) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;

}

    

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;
    
    copyRandomList(head);
    return 0;
}