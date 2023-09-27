#include<iostream>
#include<string>
#include<map>
using namespace std;
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

//I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

//APPROACH:- So if a small roman number is in left of bigger thats mean substraction 
//if it's in right thats mean addition  
int roman_to_int(string s){
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });

    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        
        if (m[s[i]] < m[s[i + 1]])
        {
            sum+=m[s[i+1]]-m[s[i]];
            i++;
            continue;
        }
        sum += m[s[i]];
    }
    return sum;


}
int main(){

    string str = "MCMIV";
    cout << "Integer form of Roman Numeral is "<< roman_to_int(str) << endl;
 
    
    return 0;
}