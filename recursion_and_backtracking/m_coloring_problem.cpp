#include<iostream>
#include<vector>
using namespace std;

//same like n queen check colors for every node and backtrack

int main(){
    int n=4;
    int m=3;

    bool graph[101][101];
    memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);
}