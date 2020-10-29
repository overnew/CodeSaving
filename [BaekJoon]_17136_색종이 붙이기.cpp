//https://www.acmicpc.net/problem/17136
#include <iostream>
using namespace std;

const int boardSize = 10;
int board[10][10];
int minUsedPaperNum=25;   //최대 사용개수는 25
int remainedColoredPaper[6] = {0,5,5,5,5,5};

bool CheckPosFill(int paperSize, int r, int c){
  for(int i=r; i<r+paperSize ; ++i)
      for(int j=c; j<c+paperSize ; ++j)
        if(board[i][j] != 1)
          return false;
    
  return true;
}

void FillBlocks(int paperSize, int r, int c,int& remainedBlocksNum, bool fill){
  if(fill){
    for(int i=r; i<r+paperSize ; ++i)
      for(int j=c; j<c+paperSize ; ++j)
        board[i][j] = 0;
    remainedBlocksNum -= paperSize*paperSize;
  }
  else{
    for(int i=r; i<r+paperSize ; ++i)
      for(int j=c; j<c+paperSize ; ++j)
        board[i][j] = 1;
    remainedBlocksNum += paperSize*paperSize;
  }
  return;
}

void FillColoredPaperDfs(int row, int col,int remainedBlocksNum,int usedPaperNum){
  if(col >= boardSize){
    FillColoredPaperDfs(row+1, 0,remainedBlocksNum,usedPaperNum);
    return ;
  }

  if(row>= boardSize){
    minUsedPaperNum = minUsedPaperNum < usedPaperNum ? minUsedPaperNum : usedPaperNum;
    return;
  }

  if(board[row][col] ==0){
    FillColoredPaperDfs(row,col+1 ,remainedBlocksNum,usedPaperNum);
    return;
  }
  if(usedPaperNum >= minUsedPaperNum)
    return;

  if(remainedBlocksNum ==0){
    minUsedPaperNum = minUsedPaperNum < usedPaperNum ? minUsedPaperNum : usedPaperNum;
    return;
  }

  for(int paperSize=5; paperSize>0 ; --paperSize)
    if(remainedColoredPaper[paperSize] >0 && remainedBlocksNum >= paperSize*paperSize)
      if(row+paperSize<=boardSize && col+paperSize<=boardSize)
        if(CheckPosFill(paperSize, row, col)){
          --remainedColoredPaper[paperSize];

          FillBlocks(paperSize,row,col,remainedBlocksNum,true);

          FillColoredPaperDfs(row,col+paperSize,remainedBlocksNum,usedPaperNum +1);

          FillBlocks(paperSize,row,col,remainedBlocksNum,false);

          ++remainedColoredPaper[paperSize];
        }
  
  return;
}

int main() {
  int remainedBlocks=0;
  ios_base::sync_with_stdio(0); cin.tie(0);

  for(int i=0; i<boardSize ; ++i)
    for(int j=0; j<boardSize ; ++j){
      cin>>board[i][j];
      if(board[i][j] == 1)
        ++remainedBlocks;
    }

  FillColoredPaperDfs(0,0,remainedBlocks,0);
  
  if(minUsedPaperNum == 25)
    cout<<-1<<'\n';
  else
    cout<<minUsedPaperNum<<'\n';

  return 0;
}
