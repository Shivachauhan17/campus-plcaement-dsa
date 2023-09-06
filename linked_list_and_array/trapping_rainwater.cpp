#include<iostream>
#include<vector>
using namespace std;

//we can calculate the unit of water being stored at a particular by knowing it left max and right max
//Brute force:- but to caculate it for every index will cause us total time complexity of O(n2)

//so:- we create two array prefix and suffix for every array index's elemnt so that we can get leftmax and rightmax 
//-> in O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        int max=0;
        for(int i=0;i<height.size();i++){
            left[i]=max<height[i]?height[i]:max;
            max=left[i];
        }
        max=0;
        for(int j=height.size()-1;j>=0;j--){
            right[j]=max<height[j]?height[j]:max;
            max=right[j];
        }
        int rainwater=0;
        for(int i=0;i<height.size();i++){
            int min=left[i]<right[i]?left[i]:right[i];
            rainwater=rainwater+(min-height[i]);
        }
        return rainwater;
    }
};