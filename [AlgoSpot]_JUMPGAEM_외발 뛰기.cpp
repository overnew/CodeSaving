//https://algospot.com/judge/problem/read/JUMPGAME
#include <iostream>
#include<string.h>
using namespace std;

int board[100][100];
int board_size;
int is_pos_board[100][100];

bool checkBoard(int r,int c){
  if(r>= board_size || c>=board_size)
    return false;

  if(is_pos_board[r][c] != -1)
    return is_pos_board[r][c];

  if(r== board_size -1 && c == board_size-1)
    return true;

  int& ret = is_pos_board[r][c];

  ret = checkBoard(r+board[r][c], c) || checkBoard(r, c+board[r][c]);

  return ret;
}

int main() { 
  int test_num;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>board_size;

    for(int j=0; j<board_size ; ++j)
      for(int k=0; k<board_size ; ++k)
        cin>>board[j][k];

    memset(is_pos_board, -1, sizeof(is_pos_board));

    if(checkBoard(0, 0))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }

  return 0;
}
