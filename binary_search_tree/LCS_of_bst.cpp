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

//In this question instead of trying the recursion it can also be done in 
//O(1) space complexity

Node* lcs(Node* root,Node* p,Node* q){
    if(root==NULL) return NULL;

    int curr=root->data;
    if(curr<p->data && curr<q->data){
        return lcs(root->right,p,q);
    }
    if(curr>p->data && curr>q->data){
        return lcs(root->left,p,q);
    }
    return root;
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(4);
    root->right=new Node(13);
    root->left->right=new Node(8);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(9);

    cout<<lcs(root, root->left->right->left,root->left->right->right)->data;

}