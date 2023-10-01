#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

void recursionRight(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursionRight(root->right, level+1, res);
        recursionRight(root->left, level+1, res);
    }

void recursionLeft(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursionLeft(root->left, level+1, res);
        recursionLeft(root->right, level+1, res);
    }
    

int main(){
    return 0;
}