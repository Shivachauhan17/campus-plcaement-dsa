#include<iostream>
#include<stack>
#include<vector>
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

    cout<<root->data<<" ";
    preOrderTrav(root->left);
    preOrderTrav(root->right);
}

//Iterative
vector<int> iterativePreOd(Node* root){
    stack<Node*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        ans.push_back(root->data);
        
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
        
    }
    return ans;
}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);  
    // preOrderTrav(root);
    vector<int> ans=iterativePreOd(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}