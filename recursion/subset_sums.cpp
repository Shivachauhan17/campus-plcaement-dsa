#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }


int main(){
    vector < int > arr{3,1,2};
  
    vector < int > ans = subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    for (auto sum: ans) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}