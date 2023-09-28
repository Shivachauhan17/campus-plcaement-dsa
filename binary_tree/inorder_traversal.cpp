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


//this was the recursive approach
void inOrderTrav(Node* root){
    if(root==NULL) return;

    inOrderTrav(root->left);
    cout<<root->data<<" ";
    inOrderTrav(root->right);
}



//Iterative:- using stack( in recursion we do return and in staack we do pop())
vector<int> inOrdIterative(Node * root,vector<int> trav){
    stack<Node*> st;
    Node* node=root;

    while (true)
    {
       if(node!=NULL){
        st.push(node);
        node=node->left;
       }
       else{
        if(st.empty()) break;
        node=st.top();
        st.pop();
        trav.push_back(node->data);
        node=node->right;
       }
    }
    return trav;
}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);  
    // inOrderTrav(root);
    vector<int> arr;
    vector<int> ans=inOrdIterative(root,arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}