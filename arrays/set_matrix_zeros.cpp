#include<iostream>
#include<vector>
using namespace std;

//Better approach
vector<vector<int>> setRowColumnZero(vector<vector<int>> arr){
    vector<int> row;
    vector<int> column;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0){
                row.push_back(i);
                column.push_back(j);
            }
        }
    }

    for(int i=0;i<row.size();i++){
        for(int j=0;j<arr[0].size();j++){
            arr[row[i]][j]=0;
        }
    }
    
    for(int i=0;i<column.size();i++){
        for(int j=0;j<arr.size();j++){
            arr[j][column[i]]=0;
        }
    }

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

//optimal solution

void optimaSet(vector<vector<int>> arr){
    int commonCorner=1;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j==0){
                    commonCorner=0;
                }
                else{
                    arr[0][i]=0;
                }
            }
        }
    }


    for(int i=1;i<arr.size();i++){
        for(int j=1;j<arr[0].size();j++){
            if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0;
            }
        }
    }

    if(arr[0][0]==0){
        for(int i=1;i<arr[0].size();i++){
            arr[0][i]=0;
        }
    }
    if(commonCorner==0){
        for(int i=1;i<arr.size();i++){
            arr[i][0]=0;
        }
    }
}

int main(){
    vector<vector<int>> arr={{1,1,1},{1,0,1},{1,1,1}};
    optimaSet(arr);
    return 0;
}