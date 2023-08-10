#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};

int main(){
    Solution a;
    vector<int> arr={4,1,2,1,2};
    cout<<a.singleNumber(arr);
    return 0;
}