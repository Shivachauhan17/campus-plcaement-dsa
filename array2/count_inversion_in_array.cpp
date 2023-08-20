#include<iostream>
#include<vector>
using namespace std;

int count=0;
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
            //**********************************
            count+=(mid-indexOfMergedArray+1);
            //*******************************
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


void mergeSort(int start,int end,vector<int>& arr){
    if(start<end){
        int mid=start+(end-start)/2;
        mergeSort(start,mid,arr);
        mergeSort(mid+1,end,arr);
        merge(start,mid,end,arr);
    }
}

int main(){
    vector<int> arr={5,3,2,4,1};
    mergeSort(0,arr.size()-1,arr);
    cout<<count;
    return 0;
}