//https://www.acmicpc.net/problem/1074
#include <iostream>
#include <cmath>
using namespace std;

int visitCount=0;

void SearchByZ(int dividedSize,int row,int col){
  if(dividedSize <= 0)
    return;

  int orderRow, orderCol, orderSum;
  orderRow = row / dividedSize;
  orderCol = col / dividedSize;
  
  orderSum = (dividedSize)*(dividedSize);
  visitCount +=  (orderRow*2 + orderCol) * orderSum;

  SearchByZ(dividedSize/2,row% dividedSize,col%dividedSize);

  return;
}

int main() {
  int N,r,c;
  int boardSize;
  cin>>N>>r>>c;

  boardSize = pow(2,N);

  SearchByZ(boardSize/2, r, c);
  cout<<visitCount<<'\n';

  return 0;
}
