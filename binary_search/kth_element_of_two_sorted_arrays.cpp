#include<iostream>
using namespace std;


//Approach:- apply binary search on the smaller array  
//t.c. :- O(log(min(n,m)))

int kthElement(int arr1[],int arr2[],int n,int m,int k){
    if(n>m){
         return kthElement(arr2,arr1,m,n,k);
    }
    int low=max(0,k-m),high=min(k,n);

    while(low<=high){
    int cut1=(low+high)>>1;
    int cut2=k-cut1;

    int l1=cut1==0?INT64_MIN:arr1[cut1-1];
    int l2=cut2==0?INT64_MIN:arr2[cut2-1];
    int r1=cut1==n?INT64_MAX:arr1[cut1];
    int r2=cut2==m?INT64_MAX:arr2[cut2];

    if(l1<=r2 && l2<=r1){
        return max(l1,l2);
    }
    else if(l1>r2){
        high=cut1-1;
    }
    else{
        low=cut1+1;
    }


    }

    return 1;

}


int main(){
    int arr1[6]={1,3,4,7,10,12};
    int arr2[4]={2,3,6,15};

    cout<<kthElement(arr1,arr2,6,4,5);

    return 0;
}