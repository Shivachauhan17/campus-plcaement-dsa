#include<iostream>
#include<vector>
using namespace std;

//Optimal  :- we will maintain a list of elements which are greate than floor(n/3) 
//but for floor(n/3) there cannot be more than 2 element in majority
//so this time we have to take two counters and two current element holders
pair<int,int> find_majorityby3(vector<int> arr){
    int n=arr.size();
    int el1=-1;
    int el2=-1;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(count1==0 && arr[i]!=el2){
            el1=arr[i];
            count1++;
        }
        else if(count2==0 && arr[i]!=el1){
            el2=arr[i];
            count2++;
        }
        else if(arr[i]==el1){
            count1++;
        }
        else if(arr[i]==el2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    return {el1,el2};
}

int main(){
    vector<int> arr={2,1,1,2,1,2,5,6};
    pair<int,int> ans=find_majorityby3(arr);
    cout<<"{"<<ans.first<<","<<ans.second<<"}"<<endl;
}