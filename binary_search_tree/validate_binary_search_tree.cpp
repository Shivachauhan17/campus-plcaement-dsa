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


bool validate(Node* root , long min,long max){
    if(root==NULL) return true;

    if(root->data>max || root->data<min) return false;

    return validate(root->left,min,root->data) && validate(root->right,root->data,max);

}




int main(){
    Node* root=new Node(5);
    root->right=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(3);

    cout<<validate(root,INT32_MIN,INT32_MAX);

    return 0;
}