#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//Efficient approach:-to solve it with greedy first sort both arrays
//

int count_platforms(vector<int> arr,vector<int> dep,int n){
    sort(arr,arr+n);
    sort(dep,dep+n);

    int ans=1;
    int count=1;
    int i=1,j=0;
    
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
}


int main(){
    vector<int> arr={50,120,200,550,700,850};
    vector<int> dep={500,550,600,700,900,1000};

    int ans=1;
    for(int i=0;i<arr.size();i++){
        int count=1;
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]>=arr[j] && arr[i]<=dep[j])||(arr[j]>=arr[i] && arr[j]<=dep[i])){
                count++;
            }
        }
        ans=max(ans,count);
        
        }
    cout<<count_platforms(arr,dep,arr.size());
    return 0;
}


