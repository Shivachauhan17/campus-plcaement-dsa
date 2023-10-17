#include<iostream>
using namespace std;


class Nodevalue{
    public:
    int maxNode,minNode,maxSize;
    Nodevalue(int minNode,int maxNode,int maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;

    }
};

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int x){
        data=x;
        left=NULL,right=NULL;
    }
};


class Solution{
    private:
    Nodevalue largestBst(Node* root){
        if(!root){
            return Nodevalue(INT32_MAX,INT32_MIN,0);
        }

        auto left=largestBst(root->left);
        auto right=largestBst(root->right);

        if(left.maxNode<root->data && root->data<right.minNode){
            return Nodevalue(min(root->data,left.minNode),
            max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
        }
        return Nodevalue(INT32_MIN,INT16_MAX,max(left.maxSize,right.maxSize));
    }

    public:
    int largestBstMain(Node* root){
        return largestBst(root).maxSize;
    };
};