#include<iostream>
#include<string>
using namespace std;


int main(){
    string s="babad";
    string resstr="";
    int reslen=0;

    int len=s.size();

    if(len%2==1){
        for(int i=0;i<len;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<=len-1 && s[l]==s[r]){
                if(r-l+1>reslen){
                reslen=r-l+1;
                resstr=s.substr(l,r-l+1);}
                l--;
                r++;
            }
        }
    }
    if(len%2==0){
        for(int i=0;i<len;i++){
            int l=i;
            int r=i+1;
            while(l>=0 && r<len-1 && s[l]==s[r]){
                if(r-l+1>reslen){
                reslen=r-l+1;
                resstr=s.substr(l,r-l+1);}
                l--;
                r++;
            }
        }
    }
    cout<<resstr<<" "<<reslen;
    return 0;
}