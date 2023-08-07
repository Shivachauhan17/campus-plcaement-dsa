#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
          int n=pref.size();
  vector<int> arr(n);
  arr[0]=pref[0];
  for(int i=1;i<n;i++){
    arr[i]=pref[i-1]^pref[i];
  }
  return arr;
    }
};

int main(){
    Solution a;
    vector<int> arr={5,2,0,3,1};
    vector<int> ans=a.findArray(arr);
    //print ans

}