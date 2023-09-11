#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void combination(vector<int> arr,int ind,vector<vector<int>>& ans,vector<int>& ds,int target){
    if(ind==arr.size()){
        if(target==0){
        ans.push_back(ds);
        
    }
    return;}

    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        combination(arr,ind+1,ans,ds,target-arr[ind]);
        ds.pop_back();
    }
    combination(arr,ind+1,ans,ds,target);
}

int main(){
    vector<int> arr={2,3,6,7};
    int target=7;
    vector<vector<int>> ans;
    vector<int> ds;
    combination(arr,0,ans,ds,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}