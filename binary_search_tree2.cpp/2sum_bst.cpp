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
    bool reverse=  true;
    BstIterator(Node* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    
    bool hasNext(){
        return !myStack.empty();
    }
    //this next will work for both next() as well as before()
    //and we are using it by manipulating reverse variable flags
    int next(){
        Node* temp=myStack.top();
        myStack.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
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

class Solution{
    public:
    bool findTarget(Node* root,int k){
         if(!root) return false;
         //for next
         BstIterator l(root,false);
         //for before
         BstIterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            else if((i+j)<k) i=l.next();
            else j=r.next();
        }
        return false;

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

    Solution s;
    cout<<s.findTarget(root,11); 

    return 0;
}