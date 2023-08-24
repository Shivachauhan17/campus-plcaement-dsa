#include<iostream>
#include<vector>
#include<map>
using namespace std; 

//Optimal:- let we are the subarray os sum s -> if we require k then we will look for s-k to see it can be excluded to get k
//-> so we will store the every subarray sum in hashmap

int sum_k(vector<int> arr,int k){
    int n=arr.size();
    map<int,int> sums;
    int sum=0;
    int count=0;
    sums[0]=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int remove=sum-k;
        count+=sums[remove];
        sums[remove]+=1;
    }
    return count;
}

int main(){
    vector<int> arr={1,2,3,-3,1,1,1,4,2,-3};
    cout<<sum_k(arr,3);
}