#include<iostream>
#include<vector>
using namespace std;

int unique_paths(int m,int n){
    if(m<0||n<0) return 0;
    if(m==0|| n==0) return 1;

    return unique_paths(m-1,n)+unique_paths(m,n-1);
    
}

int main(){
    int m=3;
    int n=7;
    cout<<unique_paths(m-1,n-1);
}
