#include<iostream>
using namespace std;


int loop4nMultiplies(int num,int n){
    int res=1;
    for(int i=1;i<=n;i++){
        res*=num;
    }
    return res;
}

int binaryForNum(int num,int n){
    int low=1;
    int high=num;
    while(low<=high){
        int mid=(low+high)/2;
        if(loop4nMultiplies(mid,n)==num){
            return mid;
        }
        else if(loop4nMultiplies(mid,n)<num){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    cout<<binaryForNum(27,3);
    return 0;
}