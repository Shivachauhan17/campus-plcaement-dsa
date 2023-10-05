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

int widthOfBinaryTree(Node* root){
    if(!root){
        return 0;
    }

    int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        int size=q.size();
        int min=q.front().second;
        int leftMost, rightMost;

        for(int i=0;i<size;i++){
            int cur_id=q.front().second-min;
            Node *temp=q.front().first;
            q.pop();
            if (i == 0) leftMost = cur_id;
            if (i == size - 1) rightMost = cur_id;
            q.pop();
            if(temp->left){
                q.push({
                    temp->left,
                    cur_id*2+1
                });
            }
            if(temp->right){
                q.push({
                    temp->right,
                    cur_id*2+2
                });
            }

        }
        ans = max(ans,  rightMost- leftMost + 1);
    }
    return ans;
}


int main(){
    Node * root = new Node(1);
    root -> left = new Node(3);
    root -> left -> left = new Node(5);
    root -> left -> left -> left = new Node(7);
    root -> right = new Node(2);
    root -> right -> right = new Node(4);
    root -> right -> right -> right = new Node(6);

    int maxWidth = widthOfBinaryTree(root);
    cout << "The maximum width of the Binary Tree is " << maxWidth;

    return 0;
}