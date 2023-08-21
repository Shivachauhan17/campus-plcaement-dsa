#include<iostream>
#include<vector>
using namespace std;

// 1.) Hashing :- t.c.->O(n), s.c. -> O(n)
int duplicate(vector<int> arr){
    if(arr.size()==0) return -1;
    int n=arr.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[arr[i]]+=1;
    }
    for(int i=0;i<n;i++){
        if(ans[i]>1) return i;
    }
    return -1;
}


// Linked List :- t.c.->O(n), s.c.->O(1) 
//pending
//gonna udate it to using xor

int main(){
    vector<int> arr={2,5,9,6,9,3,8,9,7,1};
    cout<<duplicate(arr)<<endl;
}