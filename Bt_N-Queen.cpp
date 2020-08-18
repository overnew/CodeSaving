//https://www.acmicpc.net/problem/9663

#include <iostream>
#include <string.h>
using namespace std;

int N;
int cnt =0;
bool board[14][14]; //체스를 놓기가 가능한지의 여부

void BanBoard(int r,int c){
  int i=0;
  for(i=0; i<N ;++i ){
    board[i][c] = false;
  }

  for(i=0; i<N ;++i ){
    board[r][i] = false;
  }

  int nr=r;
  int nc = c;

  while(1){
    --nr;
    --nc;
    if(0 <= nr && 0<= nc)
      board[nr][nc] = false;
    else
      break;
  }

  nr=r;
  nc=c;
  while(1){
    ++nr;
    ++nc;
    if(nr<N && nc<N)
      board[nr][nc] = false;
    else
      break;
  }

  nr=r;
  nc=c;
  while(1){
    --nr;
    ++nc;
    if(0 <= nr &&  nc<N)
      board[nr][nc] = false;
    else
      break;
  }
  
  nr=r;
  nc=c;
  while(1){
    ++nr;
    --nc;
    if(nr<N && 0<=nc)
      board[nr][nc] = false;
    else
      break;
  }

}

void Dfs(int column){
  if(column >= N){
    ++cnt;
    return;
  }

  bool board_copy[14][14];

  for(int i=0; i<N ; ++i)
   for(int j=0; j<N ; ++j)
      board_copy[i][j] = board[i][j];

  for(int i=0; i<N ; ++i){

    if(board[i][column]){
      BanBoard(i, column); 
      Dfs(column+1);

      for(int i=0; i<N ; ++i)
        for(int j=0; j<N ; ++j)
            board[i][j] = board_copy[i][j];
       
    }
    
  }

}

int main() {
  cin>> N;

  memset(board, true, sizeof(board));

  Dfs(0);
  cout<<cnt<<'\n';

  return 0;
}
