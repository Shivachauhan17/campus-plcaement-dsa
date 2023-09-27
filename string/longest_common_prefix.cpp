#include<iostream>
#include<string>
#include<vector>
using namespace std;

#include<iostream>
#include<algorithm>
 
using namespace std;
 
 //APPROACH :- The idea is to sort the array of strings and 
 //find the common prefix of the first and last string of the sorted array.

string longestCommonPrefix(string ar[], int n)
{
 
    if (n == 0)
        return "";
   
    if (n == 1)
        return ar[0];
 
    sort(ar, ar + n);
 

    int en = min(ar[0].size(),
                 ar[n - 1].size());
 

    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;
 
    string pre = first.substr(0, i);
    return pre;
}


int main(){
    string arr[]={"flower","flow"};
    cout<<longestCommonPrefix(arr,2);
}