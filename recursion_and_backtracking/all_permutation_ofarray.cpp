#include<iostream>
#include<vector>
using namespace std;

//With Recursion:- keep an freq array to keep record of this function call that which element has been included
//->and every function call run a loop which will check whether the item is picked brfore or not 
//-> t.c.:- O(n2) s.c.:-O(n)
void recur(vector<int> &ds,vector<int> &arr,vector<vector<int>> &ans,int *freq){
    if(ds.size()==arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<arr.size();i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i]=1;
            recur(ds,arr,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}


vector<vector<int>> permute(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()];
    for(int i=0;i<arr.size();i++) freq[i]=0;
    recur(ds,arr,ans,freq);
    return ans;
    
}


//With BackTracking :- we will try every number on the current index
// ->then same way go for next index
//t.c.:- O(n!*n)[n! for generating the n! permutations and n for loop]

void recur2(int index, vector < int > & nums, vector < vector < int >> & ans){
    if(index=nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        recur2(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}


vector<vector<int>> permute2(vector<int> &arr){
    vector<vector<int>> ans;
    recur2(0,arr,ans);
    return ans;
    
}


int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=permute2(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();i++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}