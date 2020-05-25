//https://www.acmicpc.net/problem/1018

#include <iostream>
using namespace std;

int N;
int M;
char board[50][50];

int Paint(int x, int y){// 첫 점을 매개로 받음
  // 두가지중에 효율적인거 고름
  int fw=0, fb=0;
  int count =0;
  char check_Wb ='W';
  char check_Bw ='B';
  char temp;

  for(int i=x; i<x+8 ; ++i){ 
    for(int j=y; j<y+8 ; ++j){
      if(count %2 == 0){
        if(board[i][j] != check_Wb)
          ++fw;
        else
          ++fb;
      }else{ // ==1
        if(board[i][j] != check_Bw)
          ++fw;
        else
          ++fb;
      }
       //cout<< "count: "<<count<<", fw,fb: "<<fw<<", "<< fb<<endl;
       ++count;
    }
    temp = check_Wb; //줄이 바귈때마다 
    check_Wb =check_Bw;
    check_Bw =temp;
  }

  return fw>fb ? fb:fw;
}

int RePaint(){
  int min = 64;
  int temp;

  for(int i=0 ; i<(N -7) ;++i){
    for(int j=0 ; j<(M-7) ;++j){
      temp = Paint(i,j);
      if(temp< min)
        min = temp; 
    }
  }

  return min;
}

int main() {
  cin >> N >> M;

  for(int i=0; i<N ; ++i){
    for(int j =0 ; j<M ; ++j){
      cin >> board[i][j];
    }
  }

  cout<< RePaint()<<endl;

  return 0;
}
