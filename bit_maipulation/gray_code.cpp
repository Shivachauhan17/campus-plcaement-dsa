#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

void combn(int n,string str,vector<string> &ans){
    if(n<=0){
    ans.push_back(str);
    return; }
    string temp=str;
    temp[n-1]='1';
    combn(n-1,temp,ans);
    combn(n-1,str,ans);
}

int change_to_int(string binaryStr){
    int result = 0;
    int size = binaryStr.size();
    
    for (int i = size - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            result += pow(2, size - 1 - i);
        }
    }
    
    return result;
}
int  main(){
    int n=2;
    vector<string> ans;
    string str(n,'0');
    vector<int> res;
    combn(n,str,ans);
    for(int i=0;i<ans.size();i++){
       int result=change_to_int(ans[i]);
       res.push_back(result);
    }
    cout<<res[0];
}