//https://www.acmicpc.net/problem/17135
#include<iostream>
#include<vector>
#include<string.h>
#include<cmath>
using namespace std;

int row,col;
int attackRange;
vector<vector<int>> board;
vector<bool> isArcherPosition;
int maxKillnum=0;

void MoveEnemy(vector<vector<int>>& turnBoard){
  for(int i=row-1; i>0 ; --i)
    turnBoard[i] = turnBoard[i-1];
  turnBoard[0] = vector<int>(col,0);
}

void StartAttack(vector<vector<int>> turnBoard, int turn, int killNum){
  if(turn >=row){
    maxKillnum = maxKillnum > killNum ? maxKillnum : killNum;
    return;
  }

  int aimEnemyPos[3][2];
  memset(aimEnemyPos,-1,sizeof(aimEnemyPos));
  int archerCol;
  int nowDistance;
  int archerOrder=0;

  for(int i=0; i<col ; ++i){
    if(isArcherPosition[i]){
      archerCol = i;
      
      int minDist = 33;

      for(int c=0; c<col ; ++c)  //가장 왼쪽의 적을 먼저확인
        for(int r=row-1; r>=0 ; --r)
          if(turnBoard[r][c] == 1){
            nowDistance = abs(row-r)+ abs(c-archerCol);
            if(nowDistance >attackRange || nowDistance>=minDist)
              break;

            minDist = nowDistance;
            aimEnemyPos[archerOrder][0] = r;
            aimEnemyPos[archerOrder][1] = c;
            
          }
      ++archerOrder;
    }

  }

  for(int i=0; i<archerOrder;++i)
    if( aimEnemyPos[i][0]!= -1 && turnBoard[aimEnemyPos[i][0]][aimEnemyPos[i][1]] == 1){
      ++killNum;
      turnBoard[aimEnemyPos[i][0]][aimEnemyPos[i][1]] = 0;
    }

  MoveEnemy(turnBoard);
  
  StartAttack(turnBoard, turn+1, killNum);

  return;
}

void ArrayArcher(){
  for(int firstArcher=0; firstArcher<col-2 ; ++firstArcher){
    isArcherPosition[firstArcher] = true;
    for(int secondArcher=firstArcher+1;  secondArcher<col-1; ++secondArcher){
      isArcherPosition[secondArcher] = true;
      for(int thirdArcher= secondArcher+1; thirdArcher<col ; ++thirdArcher){
        isArcherPosition[thirdArcher] = true;
        StartAttack(board, 0, 0);
        isArcherPosition[thirdArcher] = false;
      }
      isArcherPosition[secondArcher] = false;
    }
    isArcherPosition[firstArcher] = false;
  }

  return;
}

int main(){
  cin>>row>>col>>attackRange;

  int tempNum;

  for(int i=0; i<row ; ++i){
    vector<int> tempVec;
    for(int j=0; j<col ; ++j){
      cin>>tempNum;
      tempVec.push_back(tempNum);
    }
    board.push_back(tempVec);
  }
  
  isArcherPosition = vector<bool>(col,false);

  ArrayArcher();

  cout<<maxKillnum<<endl;

  return 0;
}
