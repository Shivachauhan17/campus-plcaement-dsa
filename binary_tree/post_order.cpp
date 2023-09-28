#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

void preOrderTrav(Node * root){
    if(root==NULL) return;

    
    preOrderTrav(root->left);
    preOrderTrav(root->right);
    cout<<root->data<<" ";
}


//Iterative:-using dual stack
vector<int> iterativePostOd(Node* curr){
    vector<int> postOrder;
    if(curr==NULL) return postOrder;

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(curr);
    while(!s1.empty()){
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left!=NULL){
            s1.push(curr->left);
        }
        if(curr->right!=NULL){
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;

}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);  
    // preOrderTrav(root);

    vector<int> ans=iterativePostOd(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}