#include<iostream>
#include<vector>
using namespace std;


//Approach:- the approach will be to find the break point of right half and left half 
//right halfs first element is answer
//->observation is in right half's first instance at odd index,second instance at even index
//in left half first instance at even index,second instance is at odd index

int binaryFindUnique(vector<int> arr){
    int n = arr.size(); 
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
    
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
            return arr[mid];
        }

        if((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}



int main(){
    vector<int> arr={1,1,2,3,3,4,4,8,8};
    cout<<binaryFindUnique(arr);
    return 0;
}