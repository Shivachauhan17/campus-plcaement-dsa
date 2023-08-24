#include<iostream>
#include<vector>
#include<map>
using namespace std;

//Aprroach:- it will work as ssame as kadanes algo 
// index[0-3] sum=3 and index[0-5] sum=3 that means -> index[4-3] sum=0
//to keep the track of sums and their last index we will use hashmap
int largest_subarray(vector<int> arr){
    map<int,int> sums;
    int n=arr.size();
    int sum=0;
    int largest=0;
    for(int i=0;i<n;i++){
        
        sum+=arr[i];
        if(sum==0) largest+=1;
        else{
        if(sums.find(sum)!=sums.end()){
            largest=max(largest,i-sums[sum]);
        }
        else{
            sums[sum]=i;
        }}
        
    }
    return largest;
}

int main(){
    vector<int> arr={1,2,3};
    cout<<largest_subarray(arr);
}