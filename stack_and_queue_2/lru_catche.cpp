#include<iostream>
#include<unordered_map>
using  namespace std;
public:
class LruCache{
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail =new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;

    LruCache(int capacity){
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }


    void addNode(Node *newNode){
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deleteNode(Node* delNode){
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }

    int get(int key_){
        if(m.find(key_)!=m.end()){
            Node* resNode=m[key_];
            int res=resNode->val;
            m.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            m[key_]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key_,int value){
        if(m.find(key_)!=m.end()){
            Node* existingNode=m[key_];
            m.erase(key_);
            deleteNode(existingNode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key_,value));
        m[key_]=head->next;
    }

};


int main(){

}