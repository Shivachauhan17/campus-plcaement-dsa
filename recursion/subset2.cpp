#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute force:- generate all the permutation and use set to store them so they will be unique
//t.c->2^n *k

//Optimal:- at same level of  recursion do not pick the same elements for next call


void subsets2(vector<int>& arr,int n,vector<vector<int>> &ans,vector<int>& ds){
        ans.push_back(ds);
        
        for(int i=n;i<arr.size();i++){
            if(i!=n && arr[i]==arr[i-1]) continue;

            ds.push_back(arr[i]);
            subsets2(arr,n+1,ans,ds);
            ds.pop_back(); 
        }

}

void util(vector<int>& arr,vector<vector<int>>& ans){
    sort(arr.begin(),arr.end());
    vector<int> ds;
    subsets2(arr,0,ans,ds);
    return;

}

int main(){
    vector<int> arr={1,2,2};
    vector<vector<int>> ans;
    util(arr,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}