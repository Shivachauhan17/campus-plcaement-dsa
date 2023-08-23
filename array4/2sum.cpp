#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Better:- hashing 
bool two_sum(vector<int> arr,int target){
    map<int,int> temp;
    for(int i=0;i<arr.size();i++){
        temp[arr[i]]=i;
    }

    for(int i=0;i<arr.size();i++){
        int a=arr[i];
        int b=target-a;
        if(temp.find(b)!=temp.end()){
            return true;
        }
        temp[b]=i;//store latter so that no element is duplicated
    }
    return false;
}

//Optimal:- first sort then apply two pointer
bool two_sum2(vector<int> arr,int target){
    sort(arr.begin(),arr.end());
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        if((arr[left]+arr[right])==target) return true;
        else if((arr[left]+arr[right])<target) left++;
        else{
            right--;
        }
    }
    return false;
} 


int main(){
    vector<int> arr={2,6,5,8,11};
    int target=14;
    cout<<two_sum(arr,14);
}