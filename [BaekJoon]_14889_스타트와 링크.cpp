//https://www.acmicpc.net/problem/14889
#include <iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;

int player_num;
int board[20][20];
int MAX_BIT;
int cache[(1<<20 )-1];

int CalcAbility(int bits){
  int result=0;
  int i_cnt=0, j_cnt=0;
  for(int i=1; i<=MAX_BIT ; i = i<<1){
    if(bits & i){
      j_cnt=0;
      for(int j=1; j<=MAX_BIT ; j = j <<1){
        if(bits & j)
          result += board[i_cnt][j_cnt];
        ++j_cnt;
      }
    }
    ++i_cnt;
  }
  cache[bits] = result;
  return result;
}

int main() {
  cin>>player_num;
  MAX_BIT = ((1<<player_num)-1);

  int temp;
  for(int i=0; i<player_num ; ++i)
    for(int j=0; j<player_num ; ++j)
      cin>>board[i][j];

  memset(cache, -1, sizeof(cache));

  int temp_bits,count,reverse_bits;
  int min_gap = INT32_MAX;

  for(int bits =1; bits<= MAX_BIT ; ++bits){
    temp_bits = bits;
    count =0;
    while(temp_bits >0){
      if(temp_bits & 1)
        ++count;
      temp_bits = temp_bits >>1;
    }

    if(count == player_num/2){
      reverse_bits = bits^MAX_BIT;
      
      if(cache[bits] == -1 && cache[reverse_bits] == -1)
        min_gap = min(min_gap, abs(CalcAbility(bits) - CalcAbility(reverse_bits)));
    }
  }

  cout<<min_gap<<'\n';
  return 0;
}
