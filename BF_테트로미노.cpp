//https://www.acmicpc.net/problem/14500

#include<iostream>
#include<vector>
using namespace std;

int row,column;
int MaxTet=0;
vector<vector<int>> board;

int tetrominoModel[19][3][2]={     /* (0,0)의 현재 위치로 부터 상대적인 위치 */
  {{0,1},{0,2},{0,3}}, 
  {{1,0},{2,0},{3,0}},
  {{0,1},{1,0},{1,1}},

  {{0,1},{0,2},{1,0}},
  {{0,1 },{0,2 },{1,2 }},
  {{0,1 },{1,1 },{2,1 }},
  {{0,1 },{ -1,1},{-2,1 }},
  {{ 0,1},{0,2 },{-1,2 }},
  {{ 1,0},{1,1 },{1,2 }},
  {{ 1,0},{2,0 },{2,1 }},
  {{0,1 },{1,0 },{2,0 }},

  {{1,0 },{ 1,1},{2,1 }},
  {{-1,1 },{0,1 },{1,0 }},
  {{ -1,1},{-1,2 },{0,1 }},
  {{ 0,1},{1,1 },{1,2 }},

  {{ -1,1},{0,1 },{0,2 }},
  {{ 1,0},{1,1 },{2,0 }},
  {{ 0,1},{ 0,2},{1,1 }},
  {{-1,1},{0,1 },{1,1 }}
};

void FindMaxTetromino(int modelIdx){
  int (&ret)[3][2] =tetrominoModel[modelIdx];
  bool isPosTet = true;
  int sum=0;

  for(int rNow=0; rNow<row ; ++rNow){
    for(int cNow=0; cNow<column ; ++cNow){
      isPosTet = true;

      if( rNow - 2<0 || row <= rNow +3 || column <= cNow+3 )
        for(int i=0; i<3 ; ++i)
          if( !(0<=rNow+ret[i][0] && rNow+ret[i][0] <row && cNow+ret[i][1] < column)){
            isPosTet = false;
            break;
          } 
      
      if(isPosTet){
        sum = board[rNow][cNow];
        for(int i=0; i<3 ; ++i)
          sum+= board[rNow+ret[i][0]][cNow+ret[i][1]];
        
        MaxTet = MaxTet > sum ? MaxTet : sum;
      }
      
    }
  }
}

int main(){
  cin>>row>>column;
  int tempNum;

  for(int i=0; i<row ; ++i){
    vector<int> tempVector;
    for(int j=0; j<column ; ++j){
      cin>>tempNum;
      tempVector.push_back(tempNum);
    }
    board.push_back(tempVector);
  }

  for(int i=0; i<19 ; ++i)
    FindMaxTetromino(i);

  cout<<MaxTet<<endl;

  return 0;
}
