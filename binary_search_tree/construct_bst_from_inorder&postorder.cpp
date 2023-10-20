#include<iostream>
#include<vector>
#include<map>
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


Node* constructTree(vector<int> postorder,vector<int> inorder,int postStart,int postEnd,
int inStart,int inEnd, map < int, int > & mp){
    if(postStart>postEnd || inStart>inEnd) return NULL;

    Node* root=new Node(postorder[postEnd]);
    int elem=mp[root->data];
    int nElems=elem-inStart;

    root->left=constructTree(postorder,inorder,postStart,postStart+nElems-1,inStart,elem-1,mp);
    root->right=constructTree(postorder,inorder,postStart+nElems,postEnd-1,elem+1,inEnd,mp);


    return root;
}


Node * buildTree(vector < int > & postorder, vector < int > & inorder) {
  int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(postorder,inorder,postStart,postEnd,inStart,inEnd,mp);
}

int main() {

  vector<int> postorder{40,50,20,60,30,10};
  vector<int> inorder{40,20,50,10,60,30};
  Node * root = buildTree(postorder, inorder);
  cout<<root->left->data;
  return 0;
}