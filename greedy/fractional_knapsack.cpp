#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Item{
    public:
    int value;
    int weight;
};

bool comparator(Item a,Item b){
    double r1=a.value/a.weight;
    double r2=b.weight/b.value;

    return r1>r2;
}

double fractionalKnapsack(int W,Item arr[],int n){
    sort(arr,arr+n,comparator);
     int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

}

int  main(){
    int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   double ans = fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}