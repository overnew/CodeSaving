//https://www.acmicpc.net/problem/12100

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int boardSize;
int maxBlock =0;

void MoveDown(vector<vector<int>> &board){
  for(int row=boardSize-1; row>0 ; --row)
    for(int col=0; col<boardSize ; ++col)
      if(board[row][col] == 0)
        for(int i=row-1; i>=0; --i)
          if(board[i][col] != 0){
            board[row][col] = board[i][col];
            board[i][col] =0;
            break;
          }

  for(int row =boardSize-1; row>0 ; --row)
    for(int col =0; col<boardSize ; ++col)
      if(board[row][col] == board[row-1][col] && board[row][col] != 0){
        board[row][col] *=2;
        board[row-1][col] =0;
      }

  for(int row=boardSize-1; row>0 ; --row)
    for(int col=0; col<boardSize ; ++col)
      if(board[row][col] == 0)
        for(int i=row-1; i>=0; --i)
          if(board[i][col] != 0){
            board[row][col] = board[i][col];
            board[i][col] =0;
            break;
          }
}

void MoveUp(vector<vector<int>> &board){
  for(int row=0; row<boardSize-1 ; ++row)
    for(int col=0; col<boardSize ; ++col)
      if(board[row][col] == 0)
        for(int i=row+1; i<boardSize ; ++i)
          if(board[i][col] != 0){
            board[row][col] = board[i][col];
            board[i][col] =0;
            break;
          }

  for(int row =0; row<boardSize-1 ; ++row)
    for(int col =0; col<boardSize ; ++col)
      if(board[row][col] == board[row+1][col] && board[row][col] != 0){
        board[row][col] *=2;
        board[row+1][col] =0;
      }

  for(int row=0; row<boardSize-1 ; ++row)
    for(int col=0; col<boardSize ; ++col)
      if(board[row][col] == 0)
        for(int i=row+1; i<boardSize ; ++i)
          if(board[i][col] != 0){
            board[row][col] = board[i][col];
            board[i][col] =0;
            break;
          }
}

void MoveRight(vector<vector<int>> &board){
  for(int col=boardSize-1; col>0 ; --col)
    for(int row=0; row<boardSize ; ++row)
      if(board[row][col] == 0)
        for(int i=col-1; i>=0 ; --i)
          if(board[row][i] != 0){
            board[row][col] = board[row][i];
            board[row][i] =0;
            break;
          }

  for(int col=boardSize-1; col>0 ; --col)
    for(int row =0; row<boardSize ; ++row)
      if(board[row][col] == board[row][col-1] && board[row][col] != 0){
        board[row][col] *=2;
        board[row][col-1] =0;
      }

  for(int col=boardSize-1; col>0 ; --col)
    for(int row=0; row<boardSize ; ++row)
      if(board[row][col] == 0)
        for(int i=col-1; i>=0 ; --i)
          if(board[row][i] != 0){
            board[row][col] = board[row][i];
            board[row][i] =0;
            break;
          }
}

void MoveLeft(vector<vector<int>> &board){
  for(int col=0; col<boardSize-1 ; ++col)
    for(int row=0; row<boardSize ; ++row)

      if(board[row][col] == 0)
        for(int i=col+1; i<boardSize ; ++i)
          if(board[row][i] != 0){
            board[row][col] = board[row][i];
            board[row][i] =0;
            break;
          }

  for(int col =0; col<boardSize-1 ; ++col)
    for(int row =0; row<boardSize ; ++row)
      if(board[row][col] == board[row][col+1] && board[row][col] != 0){
        board[row][col] *=2;
        board[row][col+1] =0;
      }

  for(int col=0; col<boardSize-1 ; ++col)
    for(int row=0; row<boardSize ; ++row)
      if(board[row][col] == 0)
        for(int i=col+1; i<boardSize ; ++i)
          if(board[row][i] != 0){
            board[row][col] = board[row][i];
            board[row][i] =0;
            break;
          }
}

void CallMoveDir(vector<vector<int>> &board,int num){
  switch(num){
    case 0:
      MoveUp(board);
    break;
    case 1:
      MoveDown(board);
    break;
    case 2:
      MoveLeft(board);
    break;
    case 3:
      MoveRight(board);
    break;
  }
}

void Play2048(vector<vector<int>> board,int moveCount){
  if(moveCount >= 5){
    for(int i=0; i<boardSize ; ++i)
      for(int j=0; j<boardSize ; ++j)
        maxBlock = maxBlock > board[i][j] ? maxBlock: board[i][j];
    return;     //이걸 안붙여서 고생을 했다..
  }
  vector<vector<int>> copy;

  for(int i=0; i<4 ; ++i){
    copy = board;
    CallMoveDir(copy, i);
    Play2048(copy, moveCount+1);
  }

}

int main(){
  vector<vector<int>> v;
  int tempNum;
  cin>>boardSize;

  for(int i=0; i<boardSize ; ++i){
    vector<int> tempVec;
    for(int j=0; j<boardSize ; ++j){
      cin>>tempNum;
      tempVec.push_back(tempNum);
    }
    v.push_back(tempVec);
  }

  Play2048(v, 0);
  cout<<maxBlock<<'\n';

  return 0;
}
