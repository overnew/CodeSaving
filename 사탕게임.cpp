//https://www.acmicpc.net/problem/3085
//할만한 부스트포스, 예제의 값만 확인한게 


#include <iostream>
#include <string>
using namespace std;

int N;
char board[50][50];

int maxLine(int x,int y){
  int big=1;
  char color;
  int conect = 1; //기본값이 1이여야함(자기 자신)
  
  for(int i=0 ; i<N ; ++i){
    color = board[x][i];
    if( i+1<N && color == board[x][i+1]){
      ++conect;
      big = max(big,conect);
    }else{
      conect = 1;
    }
  }

  conect = 1;

  for(int i=0 ; i<N ; ++i){
    color = board[i][y];
    if( i+1<N && color == board[i+1][y]){
      ++conect;
      big = max(big,conect);
    }else{
      conect = 1;
    }
  }

  return big;
}

int Bomboni(){
  int candy=1;
  char ori_f,ori_s;

  for(int i=0; i<N ; ++i){ //아래와 오른쪽만 찾으면 됨 상하좌우 모두 서칭은 중복이있음
    for(int j=0; j<N ; ++j){//우하 순서로 서칭
      
      candy = max(candy, maxLine(i,j) ); 

      if(j<N-1 && board[i][j] != board[i][j+1]){
         ori_f = board[i][j];
         ori_s = board[i][j+1];
         board[i][j] = ori_s;
         board[i][j+1] = ori_f;
        candy = max(candy,maxLine(i,j));
        candy = max(candy,maxLine(i,j+1));
        board[i][j] = ori_f;
        board[i][j+1] = ori_s;
      }

      if(i<N-1 && board[i][j] != board[i+1][j]){
         ori_f = board[i][j];
         ori_s = board[i+1][j];
         board[i][j] = ori_s;
         board[i+1][j] = ori_f;
        candy = max(candy,maxLine(i,j));
        candy = max(candy,maxLine(i+1,j));
        board[i][j] = ori_f;
        board[i+1][j] = ori_s;
      }

    }
  }

  return candy;
}

int main() {
  cin>> N;
  string temp;

  for(int i=0; i<N ; ++i){
    cin>> temp;
    for(int j=0; j<N ; ++j){
      board[i][j] = temp[j];
    }
  }

  cout<<Bomboni()<<endl;  
  return 0;
}
