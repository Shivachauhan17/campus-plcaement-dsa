#include<iostream>
#include<vector>
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

Node * build(vector<int> &arr,int &i,int bound){
    if(i==arr.size()||  arr[i]>bound) return NULL;

    Node* root=new Node(arr[i++]);
    root->left=build(arr,i,root->data);
    root->right=build(arr,i,bound);
    return root;
}

int main(){
    vector<int> arr={-10,-3,0,5,9};
    int i=0;
    Node* root=build(arr,i,INT32_MAX);
    cout<<root->right->data;

}