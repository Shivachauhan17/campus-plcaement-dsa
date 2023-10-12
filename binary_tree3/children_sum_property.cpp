#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* left,*right;

    Node(int x){
        data=x;
        left=NULL,right=NULL;
    }
};

void children_sum(Node* root){
    if(root==NULL) return;
    int child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }

    if(child>=root->data) root->data=child;

    else{
        if(root->left){
            root->left->data=root->data;
        }
        if(root->right){
            root->right->data=root->data;
        }
    }

    children_sum(root->left);
    children_sum(root->right);

    //when comeback from the left and right recursions
    int tot=0;
    if(root->right) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left or root->right) root->data=tot;

}

void printTree(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);

    return;
}


int main(){
    Node* root=new Node(40);
    root->left=new Node(10);
    root->right=new Node(20);
    root->left->left=new Node(2);
    root->left->right=new Node(5);
    root->right->left=new Node(30);
    root->right->right=new Node(40);
    children_sum(root);

    printTree(root);


    return 0;
}