#include<iostream>
#include<vector>
using namespace std;

//Hashing
pair<int,int> repeating_missing(vector<int> arr){
    int n=arr.size();
    vector<int> ans(n+1);
    pair<int,int> temp;
    temp.first=-1;
    temp.second=-1;
    for(int i=0;i<n;i++){
        ans[arr[i]]+=1;
    }
    for(int i=0;i<n+1;i++){
        if(ans[i]>1) temp.first=i;
        if(ans[i]==0) temp.second=i;
       
    }
    return temp;
}


//Optimal1 :-using mathematics equation , let two variable x(repeating),y(missing), let sum of array=s
//x2-y2=-24
//s-n(n-1)/2 -> x-y=-4
//(x-y)/(x-y)(x+y)=(x+y) -> -24/-4 ->6
//now solve these two eqn's
pair<int,int> repeating_missing2(vector<int> arr){
    int x=0;
    int y=0;
    int s=0;
    int s2=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=(arr[i]*arr[i]);
    }
    int s_natural=(n*(n+1))/2;
    int eqn1=s-s_natural;
    int s2_natural=(n*(n+1)*(2*n+1))/6;
    int eqn2=s2-s2_natural;
    eqn2=eqn2/eqn1;
    x=(eqn1+eqn2)/2;
    y=abs(eqn1-x);

    return {x,y};
}

//Optimal2:- using xor -> {4,3,6,2,1,1}^{1,2,3,4,5,6} -> 1^5 -> 4
// find a set bit -> on the basis of that set bit deveide number into two grups 
//group1-> those who have that bit zero
//group2-> those who have that bit one

pair<int,int> missing_repeating3(vector<int> arr){
    int n=arr.size();
    int zor=0;
    for(int i=0;i<n;i++){
        zor^=arr[i];
    }
    for(int i=0;i<n;i++){
        zor^=(i+1);
    }
    int num_for_set_bit=0;
    int i=0;
    while(num_for_set_bit==0){
        int temp=1<<i;
        num_for_set_bit=zor&temp;
        i++;
    }
    int group1=0;
    int group2=0;
    for(int i=0;i<n;i++){
        if((arr[i]&num_for_set_bit)!=0){
            group2^=arr[i];
        }
        else{
            group1^=arr[i];
        }
    }
    for(int i=1;i<n+1;i++){
        if((i&num_for_set_bit)!=0){
            group2^=i;
        }
        else{
            group1^=i;
        }
    }
    pair<int,int> ans;
    ans.first=group1;
    ans.second=group2;
    return ans;
}

int main(){
    vector<int> arr={4,3,6,2,1,1};
    pair<int,int> ans=missing_repeating3(arr);
    cout<<"{"<<ans.first<<","<<ans.second<<"}"<<endl;
}