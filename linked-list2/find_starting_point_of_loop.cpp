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

void createCycle(Node* &head,int pos) {
    Node* ptr = head;
    Node* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}

//Brute Force :- using the hashmap  

Node* detectCycle(Node *head){
    unordered_set<Node*> st;
    while(head!=NULL){
        if(st.find(head)!= st.end()) return head;
        st.insert(head);
        head=head->next;
    }
    return NULL;
}



//Optimal:- slow and fast pointer method
// We know that the slow pointer travels twice the fast pointer. So this makes the equation to

// 2(L1+L2) = L1+L2+nC. This makes the equation to

// L1+L2 = nC. Moving L2 to the right side

// L1 = nC-L2 and this shows why the entry pointer and the slow pointer would collide.
Node* detectCycle2(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* fast=head;
    Node* slow=head;
    Node*entry=head;

    while(fast->next != NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
            return slow;
        }

    }
    return NULL;
}

int main(){
    Node* head=new Node(8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    createCycle(head,3);

    cout<<detectCycle2(head)->data;
    return 0;
}