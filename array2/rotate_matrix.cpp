#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//optimal solution:- to rotate 90degree clockwise ->first transpose matrix -> then reverse all rows
vector<vector<int>> rotate(vector<vector<int>>& arr ){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<arr.size();i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;
}
int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans=rotate(arr);
    for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
        cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}