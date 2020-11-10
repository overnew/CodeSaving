//https://www.acmicpc.net/problem/1520
#include <iostream>
#include<string.h>
using namespace std;

int row,col;
int map[500][500];
int route_count[500][500];
int move_row[4] = {0,1,0,-1};
int move_col[4] = {1,0,-1,0};

int findDownRoute(int r, int c){
  if(r==row-1 && c== col-1)
    return 1;

  int& ret = route_count[r][c];
  if(ret != -1)
    return  ret;

  ret =0;
  int next_r,next_c;
  for(int i=0; i<4 ; ++i){
    next_r = r+move_row[i]; 
    next_c = c+ move_col[i];

    if(0<=next_r&& next_r<row && 0<=next_c && next_c<col)
      if(map[r][c] > map[next_r][next_c])
        ret += findDownRoute(next_r, next_c);
      
  }
  return ret;
}

int main() { 
  cin>>row>>col;

  for(int i=0; i<row ; ++i)
    for(int j=0; j<col ; ++j)
      cin>>map[i][j];
  
  memset(route_count, -1, sizeof(route_count));

  cout<<findDownRoute(0, 0)<<"\n";
  return 0;
}
