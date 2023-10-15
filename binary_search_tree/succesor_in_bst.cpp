#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node *left,*right;

    Node(int x){
        data=x;
        left=NULL,right=NULL;
    }
};


Node* inorderSucccesor(Node* root,Node * p){
    Node* successor=NULL;

    while(root!=NULL){
        if(p->data>=root->data){
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
    }
    return successor
}