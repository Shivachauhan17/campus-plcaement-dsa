#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node* left,*right;

    Node(int x){
        data=x;
        right=NULL;
        left=NULL;
    }
};


vector<int> bottomView(Node* root){
    vector<int> ans;
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int line=it.second;

        mp[line]=node->data;

        if(node->left!=NULL){
            q.push({node->left,line-1});
        }

        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
        
    }
    for(auto it : mp) {
        
            ans.push_back(it.second); 
        }
        return ans; 
}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);

    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    vector<int> ans=bottomView(root);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
