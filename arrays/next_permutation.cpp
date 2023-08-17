#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1.Brute force :- find each permutation in sorted order-> if permutation is equal next is the answer  

//2.optimal:- find the the brakepoint of curve(i,i+1) -> find the number from end which is least greater than arr[i]
//swap arr[i] and that num -> place numbers form i+1 to end in a sorted order(as dictionary format)
//->(n-2) is the last index where we can have a dip
vector<int> nextPermutation(vector<int> arr){
    if(arr.size()==0) return {0};
    int breakpoint=-1;//{5,4,3,2,1} -> then just reverse it
    for(int i=arr.size()-2 ;i>=0;i--){
        if(arr[i]<arr[i+1]){
        breakpoint=i;
        break;
        }
    }
    if(breakpoint==-1){
        sort(arr.begin(),arr.end());
        return arr;
    }
    else{
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>arr[breakpoint]){
                int temp=arr[i];
                arr[i]=arr[breakpoint];
                arr[breakpoint]=temp;
                break;
            }
        }
    }
    sort(arr.begin()+breakpoint+1,arr.end());
    return arr;
} 

int main(){
    vector<int> arr={5,4,3,2,1};
    vector<int> ans=nextPermutation(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}