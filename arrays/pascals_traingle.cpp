#include<iostream>
#include<vector>
using namespace std;

//type1 -> to find the particular element of the pascal traingle
int findParticular(int r,int c){
    int res=1;
    for(int i=0;i<c;i++){
        res=res*(r-i);
        res=res/(i+1);
    }
    return res;
}



//type2->to find a full row
void printRow(int n){
    int ans=1;//first element always be 1
    for(int i=1;i<n;i++){
        cout<<ans<<" ";
        ans=ans*(n-i);
        ans=ans/i;
    }
    cout<<ans;
} 
 

//type3 -> find full pascal's traingle

vector<int> genrateRow(int n){
    vector<int> ansRow;
    long long ans=1;
    ansRow.push_back(ans);
    for(int i=1;i<n;i++){
        // cout<<ans<<" ";
        ans=ans*(n-i);
        ans=ans/i;
        ansRow.push_back(ans);
    }
    return ansRow;
}


vector<vector<int>> pascalTraingle(int N){
    vector<vector<int>> ans;
    ans.push_back({1});
    for(int i=1;i<=N;i++){
        ans.push_back(genrateRow(i));
    }
    return ans;
}

int main(){
     cout<<findParticular(3,2)<<endl;
     printRow(6); 
     vector<vector<int>> ans=pascalTraingle(6);
     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
     }
    return 0;
}