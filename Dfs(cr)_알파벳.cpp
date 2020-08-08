//https://www.acmicpc.net/problem/1987

/*
  단순히 visited와 used[알파벳 순서]를 방문할시 true만 바꿔 구현하면 아래와 같은 보드는 오답이 나온다.
  3 5
  CABAZ
  UCDCY
  LTGCX
  위의 보드는 CABDGTLU로 처음 돌게 되는데 정답 루트인 CULTFDBAZYX를 돌지 못한다.
  따라서 재귀함수에서 자신이 끝날때 visited와 used를 false로 돌려 놓아야 가능성 있는 모든 루트를 순회할 수 있다.
  
  +행렬의 r,c x,y의 저장 순서를 바꿔먹어서 애먹었다. 확실히 정하고 작성하자.
  
  +다른 코드들에서 봤는데 어차피 방문한 알파벳은 접근 불가능하니 used만 사용하고 visited는 필요가 없다...
*/


#include <iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

int r,c;
vector<string> board;
bool visited[20][20];
bool used[26];
int ch_x[4] = {1,0,-1,0};
int ch_y[4] = {0,1,0,-1};

int MoveHorse(int x,int y){
  //cout<<"x: "<<x<<", y: "<<y<<'\n';

  int nx,ny,temp;
  int max_route=0;
  visited[x][y] = true;
  used[board[y][x]-'A'] = true;

  for(int i=0; i<4 ; ++i){
    nx = x+ ch_x[i];
    ny = y + ch_y[i];

    if(0<=nx && nx < c && 0<=ny && ny<r)
      if(!visited[nx][ny]&& !used[board[ny][nx]-'A']){
        //cout<<"ㄴCall-> x: "<<nx<<", y: "<<ny<<'\n';

        temp = MoveHorse(nx, ny)+1;
        max_route = max_route > temp? max_route : temp;
      }
        
  }
  used[board[y][x]-'A'] = false;
  visited[x][y] = false;
  //cout<<"End-> x: "<<x<<", y: "<<y<<'\n';
  return max_route;
}

int main() {
  string temp;
  int result;
  cin>>r>>c;
  for(int i=0; i<r ; ++i){
    cin>>temp;
    board.push_back(temp);
  }
  memset(visited, false, sizeof(visited));
  memset(used, false, sizeof(used));

  result = MoveHorse(0, 0)+1;
  cout<<result<<'\n';

  return 0;
}
