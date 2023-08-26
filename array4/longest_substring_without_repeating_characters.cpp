#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<map>
using namespace std;
//Optimal1:-
// We will have two pointers left and right. 
// Pointer ‘left’ is used for maintaining the starting point of the substring 
// while ‘right’ will maintain the endpoint of the substring.’ right’ 
// pointer will move forward and check for the duplicate occurrence of the current element 
// if found then the ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

int longestSubstring(string str) {

  if(str.size()==0)
      return 0;
  int maxans = 0;
  unordered_set < int > st;
  int left = 0;
  for (int right = 0; right < str.length(); right++) // outer loop for traversing the string
  {
    if (st.find(str[right]) != st.end()) //if duplicate element is found
    {
      while (left < right && st.find(str[right]) != st.end()) {
        st.erase(str[left]);
        left++;
      }
    }
    st.insert(str[right]);
    maxans = max(maxans, right - left + 1);
  }
  return maxans;
}


//Optimal2:-directly jump to the right index if its being repeated
int longestSubstring2(string str) {
    map<int,int> m;
    int left=0;
    int right=0;
    int len=1;
    int n=str.size();
    while(right<n){
        if(m.find(str[right])!=m.end()){
            left=max(left,m[str[right]]+1);
        }
        m[str[right]]=right;
        len=max(len,right-left+1);
        right++;
    }
    return len;
}

int main(){
    cout<<longestSubstring2("abcaabcdba");
    return 0;
}