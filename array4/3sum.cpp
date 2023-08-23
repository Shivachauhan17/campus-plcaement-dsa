#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

//Better:-
//target always is zero
//a+b+c=0 -> c=-(a+b)
vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {//when next iteration of i=1 will come all the iteration on the i=0 willhave been already try 
      set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


//OPtimal:- first sort he array -> for a element i find other elements using two pointer j,k
vector<vector<int>> triplet2(vector<int> arr){
    set<vector<int>> st;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++){
        vector<int> temp;
        int left=i+1;
        int right=arr.size()-1;
        while(left<right){
            if(arr[i]== -(arr[left]+arr[right])){
                temp={arr[i],arr[left],arr[right]};
                sort(temp.begin(),temp.end());
                st.insert(temp);
                left++;
                right--;
            }
            else if((arr[i]+arr[left]+arr[right])>0){
                right--;
            }
            else{
                left++;
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=triplet2(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}