#include<iostream>
#include<vector>
#include<queue>
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

vector<int> levelOrder(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        
        ans.push_back(temp->data);

    }
    return ans;

}


int main(){
    
}