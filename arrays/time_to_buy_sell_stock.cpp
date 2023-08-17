#include<iostream>
#include<vector>
using namespace std;


//optimal approach:- initial profit 0 because if array is [5,4,3,2,1] there always will be loss 
//-> keep the pointer on minimum element at left(time to but stock) 
//->calculate its maximum difference with elements on riight(best time to sell stock)
int maxprofit(vector<int> arr){
    // if(arr.size()==0) return 0;
    int left_min=arr[0];
    int profit=0;
    for(int i=0;i<arr.size();i++){
        left_min=min(left_min,arr[i]);
        profit=max(profit,arr[i]-left_min);
    }
    return profit;
}

int main(){
    vector<int> arr={7,1,5,3,6,4};
    cout<<maxprofit(arr)<<endl;
    return 0;
}