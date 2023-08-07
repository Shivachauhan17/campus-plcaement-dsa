#include<iostream>
#include<String>
using  namespace std;




class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.length();
        int blen=b.length();

        int i=0,carry=0;
        string ans="";
        while(i<alen||i<blen||carry!=0){//when carry is 1
            int x=0;
            if(i<alen && a[alen-i-1]=='1'){//start from LSB , checking in bit is 1
                x=1;
            }
            int y=0;
            if(i<blen && b[blen-i-1]=='1'){//start from LSB,checking in bit is 1
                y=1;
            }
            //let assume carry is 0 in below three cases
            //if bits 1,0 '1' will be added in ans string and carry=0
            //if bits 1,1  '1' will be added in the ans string and carry=1
            //if bits 0,0 '0' will added in the ans string ans carry=0
            ans = to_string((x+y+carry)%2)+ans;
            carry=(x+y+carry)/2;
            i+=1;
        
            }
            return ans;
        }   
};


int main(){
    string a="11";
    string b="1";
    Solution A;
    cout<<A.addBinary(a,b);
}