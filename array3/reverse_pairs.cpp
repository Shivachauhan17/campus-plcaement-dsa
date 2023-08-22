#include<iostream>
#include<vector>
using namespace std;


// int count=0;
//Optimal-> can be solved using integrated mergesort
void merge(int start,int mid,int end,vector<int>& arr){
    int leftSubarrayLen=mid-start+1;
    int rightSubarrayLen=end-start;
    vector<int> leftSubarray(leftSubarrayLen);
    vector<int> rightSubarray(rightSubarrayLen);
    for(int i=0;i<leftSubarrayLen;i++){
        leftSubarray[i]=arr[i+start];
    }
    for(int i=0;i<rightSubarrayLen;i++){
        rightSubarray[i]=arr[i+mid+1];
    }
    int indexOnSubarrayOne=0;
    int indexOnSubarrayTwo=0;
    int indexOfMergedArray=start;
    while(indexOnSubarrayOne<leftSubarrayLen && indexOnSubarrayTwo<rightSubarrayLen){
        if(leftSubarray[indexOnSubarrayOne]<rightSubarray[indexOnSubarrayTwo]){
            arr[indexOfMergedArray]=leftSubarray[indexOnSubarrayOne];
            indexOnSubarrayOne++;
        }
        else{
            arr[indexOfMergedArray]=rightSubarray[indexOnSubarrayTwo];
            indexOnSubarrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexOnSubarrayOne<leftSubarrayLen){
        arr[indexOfMergedArray]=leftSubarray[indexOnSubarrayOne];
        indexOnSubarrayOne++;
        indexOfMergedArray++;

    }
    
    while(indexOnSubarrayTwo<rightSubarrayLen){
        arr[indexOfMergedArray]=rightSubarray[indexOnSubarrayTwo];
        indexOnSubarrayTwo++;
        indexOfMergedArray++;

    }
}

//t.c. :- O(n1+n2)
int countPairs(vector<int> arr,int start,int mid,int end){
    int count=0;
    int right=mid+1;
    for(int i=start;i<=mid;i++){
        while(right<=end && arr[i]>(2*arr[right])){
            right++;
        }
        count+=(right-(mid+1));
    }
    // cout<<count;
    return count;
}

int mergeSort(int start,int end,vector<int>& arr){
    if(start>=end) return 0;
        int count=0;
        int mid=start+(end-start)/2;
        count+=mergeSort(start,mid,arr);
        count+=mergeSort(mid+1,end,arr);
        count+=countPairs(arr,start,mid,end);
        merge(start,mid,end,arr);
        // cout<<count;
        return count;
}



int main(){
    vector<int> arr={4, 1, 2, 3, 1};
    cout<<mergeSort(0,arr.size()-1,arr);
}