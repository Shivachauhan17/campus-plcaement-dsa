#include<iostream>
#include<vector>
using namespace std;


//Optimal:- to find out the element which is appearing more than n/2 -> first apply moores voting algo 
//verify moores voting algo

int majority_element(vector<int> arr){
    int n=arr.size();
    int curr=arr[0];
    int count=0;

    for(int i=0;i<n;i++){
        if(curr==arr[i]) count++;
        else count--;
        if(count==0){
            curr=arr[i];
            count++;
        }
    }
    //verify
    if(count!=0){
        count=0;
        for(int i=0;i<n;i++){
            if(curr==arr[i]) count++;
        }
        if(count>(n/2)){
            return curr;
        }
    }
    return -1;
}


int main(){
    vector<int> arr={2,2,1,1,1,3,3};
    cout<<majority_element(arr);
    
}