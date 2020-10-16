//https://algospot.com/judge/problem/read/BOARDCOVER

#include<iostream>
#include<string.h>
using namespace std;

char board[20][20];
int height, width;
int whiteNum;

int blockModel[4][2][2] ={{{1,0},{1,1}}, {{0,1},{1,1}},{{1,-1},{1,0}},{{0,1},{1,0}} };  //row, column순

bool FindWhiteBlock(int &r, int &c){
  int nextRow=r, nextCol=c;
  while(1){ 
    if(board[nextRow][nextCol] == '.'){
      r = nextRow;
      c = nextCol;
      return true;
    }

    if(nextCol < width){
      if(nextCol == width-1){
        if(nextRow == height-1)
          return false;   //다음 흰 블록을 찾지 못함-> 끝남

        nextCol=0;
        ++nextRow;
      }else
        ++nextCol;
    }
  }
  return false;
}


int CountCoverWhite(const int r,const int c){

  int ret=0;
  int firstBlockRow, firstBlockCol, secondBlockRow, secondBlockCol;
  int nextRow, nextCol;

  for(int i=0; i<4 ; ++i){
    firstBlockRow = r+blockModel[i][0][0];
    firstBlockCol = c+blockModel[i][0][1];
    secondBlockRow = r+blockModel[i][1][0];
    secondBlockCol = c+blockModel[i][1][1];

    if( secondBlockRow< height && 0<=firstBlockCol && firstBlockCol<width&& secondBlockCol <width )
      if(board[firstBlockRow][firstBlockCol] == '.'&& board[secondBlockRow][secondBlockCol] == '.'){
        whiteNum -= 3;

        if(whiteNum ==0){
          whiteNum +=3;
          return 1;
        }
        
        board[r][c] = board[firstBlockRow][firstBlockCol] = board[secondBlockRow][secondBlockCol] ='#';

        nextRow =r; nextCol =c;
        if(FindWhiteBlock(nextRow, nextCol)){

          ret += CountCoverWhite(nextRow, nextCol); 
        
        } 
        
        whiteNum +=3;
        board[r][c] = board[firstBlockRow][firstBlockCol] = board[secondBlockRow][secondBlockCol] = '.';
      }

  }

  return ret;
}

int main(){
  int testNum;
  int startRow, startCol;
  cin>>testNum;

  for(int i=0; i<testNum ; ++i){
    cin>>height>>width;

    whiteNum =0;
    for(int j=0; j<height ; ++j)
      for(int k=0; k<width ; ++k){
        cin>>board[j][k];
        if(board[j][k] == '.')
          ++whiteNum;
      }
    
    if(whiteNum %3 != 0 || whiteNum ==0)
      cout<<'0'<<'\n';
    else{
      startRow =0;
      startCol =0;
      FindWhiteBlock(startRow, startCol);
      cout<<CountCoverWhite(startRow, startCol)<<'\n';
    }
    
  }

  return 0;
}
