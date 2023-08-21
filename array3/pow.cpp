#include<iostream>
#include<vector>
using namespace std;

//Optimal:- we will calculate the pow using the Binary exponation
//if -n is negative than to calculate x^-n -> calculate 1 / x^n
//when n(even) ans=ans*ans -> when n(odd) ans=ans*

double mypow(int a,int n){
    double ans=1.0;
    long nn=n;

    if(nn<0){-1*nn;};

    while(nn>0){
        if(nn%2==1){
            ans=ans*a;
            nn=nn-1;
        }
        else{
            a=a*a;
            nn=nn/2;
        }
    }
    if(n<0) ans=(double)(1.0)/(double)(ans);
    return ans;
}

int main(){
    cout<<mypow(2,10);
    return 0;
}