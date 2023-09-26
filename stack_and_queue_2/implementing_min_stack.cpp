#include<iostream>
#include<stack>
using namespace std;

//Solution one:- to store the pairs of current value and current minimum value 
//t.c.:- O(1) s.c.:-O(2n)
class MinStack1{
    stack<pair<int,int>> st;
    
    public:
    void push(int x){
        int min;
        if(st.empty()){
            min=x;
        }
        else{
            min=std::min(st.top().second,x);
        }
        st.push({x,min});
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int geMin(){
        return st.top().second;
    }

};

//Solution2 :- without using the extra space 
//if curr number to push is then push the modified value which is 
//a push(2*val-min) into the stack and will update min to the value
//of the original number. if it's not then we will just push it as it is.
class MinStack2{
    stack<long long> st;
    long long mini;

    public:
    MinStack2(){
        while(st.empty() ==false) st.pop();
        mini=INT32_MAX;
    }

    void push(int value){
        long long val=value;
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val<mini){
                st.push(2*val*1LL-mini);
            }
            else{
                st.push(val);
            }
        }
    }

    void pop(){
        if(st.empty()) return;
        long long el=st.top();
        st.pop();

        if(el<mini){
            mini=2*mini-el;
        }
    }

};




int main(){
    return 0; 
}