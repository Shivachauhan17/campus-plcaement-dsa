#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right,*next;

    Node(int x){
        data=x;
        left=NULL,right=NULL,next=NULL;
    }
};


void point_nexts(Node* root){

    Node* curr=root;
    Node* next=root->left;
    while(curr && next){
        curr->left->next=curr->right;
        if(curr->next){
        curr->right->next=curr->next->left;}

        curr=curr->next;
        if(!curr){
            curr=next;
            next=curr->left;
        }

        
    }
}


int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    point_nexts(root);

    cout<<(root->left->next->data);

}
