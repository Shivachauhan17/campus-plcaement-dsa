#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//optimal-approach:- first sort all the pair according to the first element -> check if first element of next pair is 
//less than the second element of pair -> exp: (1,3),(2,4) -> (1,4)
//->update 4 too if same condtion -> if not look to make more such pairs

vector<pair<int,int>> mergePairs(vector<vector<int>> arr){
    sort(arr.begin(),arr.end());
    vector<pair<int,int>> ans;
    pair<int,int> temp(arr[0][0],arr[0][1]);
    for(int i=0;i<arr.size();i++){
        if(arr[i][0]<temp.second){
            temp.second=arr[i][1];
        }
        else{
            ans.push_back(temp);
            temp.first=arr[i][0];
            temp.second=arr[i][1];
        }
    }
    ans.push_back(temp);
    return ans;
}

int main(){
    vector<vector<int>> arr={{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<pair<int,int>> ans= mergePairs(arr);
    for(int i=0;i<ans.size();i++){
        cout<<"("<<ans[i].first<<","<<ans[i].second<<")";
    }
}