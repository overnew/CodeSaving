//https://www.acmicpc.net/problem/10835
#include <iostream>
#include<string.h>
using namespace std;

int card_num;
int left_card[2000];
int right_card[2000];
int cache[2000][2000];

int playCardGame(int l,int r){
  if(l>=card_num || r>=card_num)
    return 0;

  int& ret = cache[l][r];
  if(ret != -1)
    return ret;

  int max_score =0;
  
  if(left_card[l]> right_card[r]){
    max_score = right_card[r] + playCardGame(l,r+1);
  }

  max_score = max(max_score,playCardGame(l+1, r));
  max_score = max(max_score,playCardGame(l+1, r+1));

  ret = max_score;
  return ret;
}

int main() {
  cin>>card_num;

  for(int i=0; i<card_num ; ++i)
    cin>>left_card[i];

  for(int i=0; i<card_num ; ++i)
    cin>>right_card[i];

  memset(cache, -1, sizeof(cache));

  cout<<playCardGame(0, 0)<<'\n';
  return 0;
}
