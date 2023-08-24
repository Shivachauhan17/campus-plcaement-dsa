#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


//Better :- here we have to find the consecutive subsequence so a better approach will be first sorting then solving
int longestSubsequence(vector<int> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int longest=1;
    int curr_long=1;
    int last_smallest=arr[0];
    for(int i=1;i<arr.size();i++){
        if((arr[i]-last_smallest)==1){//if next element is consecurtive
            curr_long+=1;
            last_smallest=arr[i];
            longest=longest<curr_long?curr_long:longest;
        }
        else if((arr[i]-last_smallest)==0){//if next element is same then just move ahead witout doing anything 
            continue;
        }
        else if((arr[i]-last_smallest)>1){//if next element is not consecutive but more a bigger
            curr_long=1;
            last_smallest=arr[i];
        }
    }
    return longest;
}


//Optimal:-this optimal solution is only optimal under some constraint that there is no collision happening in the set
//first store the elements into a unordered set -> tc.= O(n)+O(2n) [if we are considering no collisions]
int longestSubsequence2(vector<int> arr){
    int n=arr.size();
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int longest=0;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
        int curr_long=1;
        int last_smallest=it;
        while(st.find(last_smallest+1)!=st.end()){
            last_smallest=last_smallest+1;
            curr_long+=1;
        }
        longest=max(longest,curr_long);
        }

    }
    return longest;
}


int main(){
    vector<int> arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    cout<<longestSubsequence(arr);

}