//https://www.acmicpc.net/problem/2447
// 분할정복
//이렇게 쉬운걸 고민하다니..
//배열에 모두 빈칸으로 채우고 별만 수정하면 되는데 배열이 너무 클까봐 다른걸로 하려다가 낭패봤다..
// 이제부터는 최대 배열의 크기를 잘 확인 하고 가능하다 싶으면 이렇게하기
#include <iostream>
using namespace std;

int N;
char star[3000][3000];

void Dot(int n, int x, int y){
  if(n == 1){
    star[x][y] = '*';
    return;
  }

  int n_div = n/3;
  for(int i=0; i<3 ; ++i){
    for(int j=0; j<3 ; ++j){
      if(i==1 && j ==1)
        continue;
      Dot(n_div, x+(i*n_div), y+(j*n_div) );
    }
  }
}


int main() {
  cin>> N;

  for(int i=0; i<N ; ++i){
    for(int j=0; j<N ;++j ){
      star[i][j] = ' ';
    }
  }
  Dot(N,0,0);

  for(int i=0; i<N ; ++i){
    for(int j=0; j<N ;++j ){
      cout<<star[i][j];
    }
    cout<<endl;
  }

  return 0;
}
