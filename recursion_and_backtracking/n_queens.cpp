#include<iostream>
#include<vector>
using namespace std;


bool issafe(vector<vector<int>> board,int row ,int col){
    for(int i=0;i<col;i++){
        if(board[i][col]){
            return false;
        }
    }

    int maxleft=min(row,col);
    for(int i=1;i<=maxleft;i++){
        if(board[row-i][col-i]){
            return false;
        }
    }

    int newcol=board.size()-col-1;
    int maxright=min(row,newcol);

    for(int i=1;i<=maxright;i++){
        if(board[row-i][col+i]){
            return false;
        }
    } 

    return true;
}

int queen(vector<vector<int>> board,int row){
    if(row==board.size()){
        return 1;
    }

    int count=0;
    for(int col=0;col<board.size();col++){
        if(issafe(board,row,col))
            board[row][col]=true;
        count+=queen(board,row+1);
        board[row][col]=false;
    }
    return count;   
}





int main(){
    vector<vector<int>> board={ { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    int count=queen(board,0);
    cout<<count;
}