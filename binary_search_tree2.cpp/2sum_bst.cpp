// if this problem will solved without bst iterator this can solved using inorder traversal 
//storing into a array

#include<iostream>
#include<stack>
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

class BstIterator{
    public:
    stack<Node*> myStack;
    bool reverse;
    BstIterator(Node* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    
    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        Node* temp=myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->data;
    }

    private:
    void pushAll(Node* node){
        for(;node!=NULL;){
            myStack.push(node);
            if(reverse==true){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
    }
};




int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->left->left=new Node(2);
    root->left->right=new Node(8);
    root->left->right->left=new Node(6);

    root->right=new Node(15);
    root->right->left=new Node(13);
    root->right->right=new Node(17);

    BstIterator i(root,true);
    cout<<i.next();
    cout<<i.next();

    return 0;
}