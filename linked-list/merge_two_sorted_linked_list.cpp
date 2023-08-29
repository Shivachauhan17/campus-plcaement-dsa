#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};

Node* merge(Node* a,Node* b){
    Node dummy;
    Node* tail=&dummy;
    if(a==NULL){
        tail->next=b;
        return dummy.next;
    }
    if(b==NULL){
        tail->next=a;
        return dummy.next;
    }

    while(1){
        if(a->data<b->data){
            
        }
    }
    
}

 int main(){
 }
 