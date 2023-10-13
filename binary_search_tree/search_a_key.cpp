#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* node, int key)
{
    if (node == NULL)
        return new Node(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    return node;
}



Node* search(Node* root,int key){
    if(root==NULL || root->data==key){
        return root;
    }

    if(key<root->data){
        return search(root->left,key);
    }
    else if(key>root->data){
        return search(root->right,key);
    }

    return root;
}


int main(){
    Node* root=new Node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout<<search(root,60)->data;

    return 0;
}