#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Approach:-first we will store the meetings in (strat time,end time,index)1 based indexing in a 2d vector
//-> then sort the that vector according to ending time -> so that we can keep track of when last meeting ended
//t.c.:-O(n)+O(nlogn)+O(n), s.c.:- O(n)

class Meeting{
    public:
    int start;
    int end;
    int index;
};

bool static comparator(class Meeting m1, Meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.index < m2.index) return true;
         return false;
      }

void num_of_meeting(vector<int> start,vector<int> end){
    int n=start.size();
    Meeting meeting[n];
    for(int i=0;i<start.size();i++){
        meeting[i].start=start[i];
        meeting[i].end=end[i];
        meeting[i].index=i+1;
    }   

    sort(meeting,meeting+n,comparator);

    vector<int> ans;
    int limit=meeting[0].end;
    ans.push_back(meeting[0].index);

    for(int i=1;i<n;i++){
        if(meeting[i].start>limit){
            limit=meeting[i].end;
            ans.push_back(meeting[i].index);
        }
    }
    cout<< "The order in which the meetings will be performed is"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"";
    }

}


int main(){
    vector<int> startime={1,0,3,8,5,8};
    vector<int> endtime={2,6,4,9,7,9};
    num_of_meeting(startime,endtime);
}