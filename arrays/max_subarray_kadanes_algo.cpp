#include<iostream>
#include<vector>
using namespace std;

long long kadanes(vector<int> arr){
    long long maxi=INT64_MIN;
    long long sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr={ -2, 1, -3, 4, -1, 2, 1, -5, 4};
    long long ans=kadanes(arr);
    cout<<ans;
}