#include<iostream>
#include<vector>
using namespace std;


vector<int> sort012(vector<int> arr){
    if (arr.size()==0) return arr;
    int n=arr.size();
    int low=0;
    int mid=0;
    int high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            int temp=arr[low];
            arr[low]=arr[mid];
            arr[mid]=temp;
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            int temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            high--;
        }
    }
    return arr;
}

int main(){
    vector<int> arr={2,0,2,1,1,0};
    vector<int> ans=sort012(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}