#include<iostream>
#include<string>
#include<stack>
using namespace std;

//Aproach1 :- use a stack to store the word then every time pick the word and add to a string 
//->they will automatically become in reverse order
string reverse(string s){
    string str="";
    stack<string> st;

    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            st.push(str);
            str="";
        }
        else{
            str+=s[i];
        }
    }
    st.push(str);
    str="";

    while(!st.empty()){
        str+=st.top()+" ";
        st.pop();
    }

    return str;

}

string reverse2(string s){
    string temp="";
    string ans="";
    int left=0;
    int right=s.size()-1;
    while(left<=right){
        char ch= s[left];
        if(ch!=' '){
            temp+=ch;
        }
        else if(ch==' '){
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }

    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    return ans;
}


int main(){
    string in="i am supposed to go";
    cout<<reverse2(in);
    return 0;
}