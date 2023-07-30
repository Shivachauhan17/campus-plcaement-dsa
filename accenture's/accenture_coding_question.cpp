#include<iostream>
#include<vector>
#include<string>
using namespace std;
//********************************Accenture question 1**********************************************************
// int rats(int r, int unit,int n,vector<int> arr){//total food required i*unit=7*2
//   if(n==0){
//     return -1;
//   }
//   int totalFoodRequired=r*unit;
//   int foodTillNow=0;
//   int house=0;

//   for(house=0;house<n;house++){
//     foodTillNow+=arr[house];
//     cout<<foodTillNow<<" ";
//     if(foodTillNow>=totalFoodRequired){
//       break;
//     }
//   }
//   if(totalFoodRequired>foodTillNow){
//     return 0;
//   }
//   return house+1;
// }


//*****************************************************Accenture question 2**************************************************
// int bit_op(string str){
//   int n=str.length();
//   int res=(str[0]=='1')?1:0;
//   for(int i=0;i<n;i=i+2){
//     //cout<<str[i+1]<<" ";
//     cout<<res<<" ";
//     if(str[i+1]=='C'){
//       int temp=(str[i+2]=='1')?1:0;
//       res=res^temp;
//     }
//     else if(str[i+1]=='B'){
//       int temp=(str[i+2]=='1')?1:0;
//       res=res|temp;
//     }
//     else if(str[i+1]=='A'){
//       int temp=(str[i+2]=='1')?1:0;
//       res=res&temp;
//     }
    
//   }
//   return res;
// }
//**************************************************Accenture question 3***************************************

bool is_pass(string str){
  if(str.length()==0){
    return 0;
  }
  if(int(str[0])>48||int(str[0])<57){
    return 0;
  }
  int n=str.length();
  bool len_flag=(n>=4)?1:0;
  bool num_digit_flag=0;//ASCII(88-57)
  for(int i=1;i<n;i++){
    if(int(str[i])>=48||int(str[i])<=57){
      num_digit_flag=1;
      break;
    }
  }
  bool capital_flag=0;
  for(int i=0;i<n;i++){
    if(int(str[i])>=65||int(str[i])<=90){
      capital_flag=1;
      break;
    }
  }
  bool space_slash_flag=0;
  for(int i=0;i<n;i++){
    if(str[i]==' '||str[i]=='/'){
      space_slash_flag=1;
      break;
    }
  }
  return (capital_flag && space_slash_flag && len_flag && num_digit_flag);
}
int main(){
  // vector<int> arr={2 ,8 ,3 ,5 ,7, 4, 1 ,2};
  // cout<<rats(7,2,8,arr);
  
  //string str="1C0C1C1A0B1";
  //bit_op(str);


  return 0;
}