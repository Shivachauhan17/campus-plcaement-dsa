#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;


//Better:- a+b+c+d=target -> try to find out (target-(b+c+d)) because a=target-(b+c+d)
vector<vector<int>> quad(vector<int> arr,int target){
    set<vector<int>> st;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            set<int> hashset;
            for(int k=j+1;k<arr.size();k++){
                int a=target-(arr[i]+arr[j]+arr[k]);
                if(hashset.find(a)!=hashset.end()){
                    vector<int> temp={arr[i],arr[j],arr[k],a};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);

            }

        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


//Optimal:- for first two elements run loop and for other two elements take two pointer approach
vector<vector<int>> quad2(vector<int> arr,int target){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    set<vector<int>> st;
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int left=j+1;
            int right=n-1;
            while(left<right){
                if((arr[i]+arr[j]+arr[left]+arr[right])==target){
                    vector<int> temp={arr[i],arr[j],arr[left],arr[right]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    left++;
                    right--;
                }
                else if((arr[i]+arr[j]+arr[left]+arr[right])<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr={1,0,-1,0,-2,2};
    vector<vector<int>> ans=quad2(arr,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}