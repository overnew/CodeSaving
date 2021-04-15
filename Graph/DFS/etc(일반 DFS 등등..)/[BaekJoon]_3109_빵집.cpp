//https://www.acmicpc.net/problem/3109
#include<iostream>
#include<string.h>
using namespace std;

int row,col;
char board[10000][500];
bool visited[10000][500];
int change_pos[3][2] = { {-1,1}, {0,1}, {1,1} };
int cnt_pipeline =0;

bool InstallPipe(int r, int c){
  visited[r][c] = true;
  
  if(c == col-1){ //끝에 도달한 경우
    ++cnt_pipeline;
    return true;
  }

  int next_r, next_c;
  for(int i=0; i<3 ; ++i){
    next_r = r + change_pos[i][0];
    next_c = c + change_pos[i][1];

    if(next_r<row && 0<=next_r && 0<=next_c &&  next_c<col)
      if(board[next_r][next_c] =='.' && !visited[next_r][next_c])  //비어있는 경우만 진행
        if(InstallPipe(next_r, next_c)){
          board[next_r][next_c] = 'x';
          return true;
        }
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>row>>col;

  char temp;
  for(int i = 0; i<row ; ++i)
    for(int j=0; j<col ; ++j)
      cin>>board[i][j];

  memset(visited, false,sizeof(visited));
  for(int r =0; r<row ; ++r)
    InstallPipe(r, 0);
  
  cout<<cnt_pipeline<<'\n';

  return 0;
}
