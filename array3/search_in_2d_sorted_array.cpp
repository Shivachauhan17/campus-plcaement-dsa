#include<iostream>
#include<vector>
using namespace std;

//Using binary search t.c.: O(log(m*n))
void bsearch_in_2d(vector<vector<int>>& arr,int element){    
    int m=arr.size();
    int n=arr[0].size();

    int left=0;
    int right=m*n-1;
    while(left<=right){
        int mid=(left+(right-left)/2);
        if(element==arr[(mid/n)][(mid%n)]){
            cout<<"{"<<(mid/n)<<","<<(mid%n)<<"}";
        }
        if(element<arr[(mid/m)][(mid%n)]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

}

int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    bsearch_in_2d(arr,8);
    return 0;
}