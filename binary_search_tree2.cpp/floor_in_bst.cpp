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


Node* floor(Node* root,int p){
    if(root==NULL) return root;
    Node* floor;
    while(root){
        if(root->data>p){
            root=root->left;
        }
        if(root->data==p){
            floor=root;
            return floor;
        }
        else{
            floor=root;
            root=root->right;
        }

    }
    return floor;

}


int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(8);
    root->left->right->left=new Node(6);

    root->right=new Node(15);
    root->right->left=new Node(13);
    root->right->right=new Node(17);

    cout<<floor(root,7)->data;

    return 0;
}