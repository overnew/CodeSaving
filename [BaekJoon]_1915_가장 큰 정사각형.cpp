//https://www.acmicpc.net/problem/1915
#include <iostream>
#include<string>
using namespace std;

int row,col;
int board[1000][1000];
int change_row[3] = {-1,-1,0};
int change_col[3] = {-1,0,-1};

int main() { 
  cin>>row>>col;

  int max_length =0;
  string temp;
  for(int i=0; i<row ; ++i){
    cin>>temp;
    for(int j=0; j<col ; ++j){
      board[i][j] = temp[j] -'0';
      if(board[i][j] == 1)
        max_length =1;
    }
  }

  int min_length=1001;
  for(int r=1; r<row ; ++r)
    for(int c=1; c<col ; ++c){
      min_length=1001;
      if(board[r][c] !=0){
        for(int i=0; i<3 ; ++i)
          min_length = min(min_length, board[r+change_row[i]][c+change_col[i]]);
        
        board[r][c] = min_length+1;

        if(min_length +1 > max_length)
          max_length = min_length+1;
      }
    }

  cout<<max_length*max_length<<'\n';
  
  return 0;
}
