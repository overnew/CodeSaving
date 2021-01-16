//https://www.acmicpc.net/problem/1062
#include <iostream>
#include<string.h>
#include<string>
using namespace std;

int word_num, learned_num;
int words_bits[50];
const int MAX_BIT = (1<<26 )-1;

int main() {
  cin>>word_num>>learned_num;

  memset(words_bits, 0 ,sizeof(words_bits));
  string temp;
  int start_bit = 0;
  start_bit |= (1<<('a' - 'a'));
  start_bit |= (1<<('c' - 'a'));
  start_bit |= (1<<('i' - 'a'));
  start_bit |= (1<<('n' - 'a'));
  start_bit |= (1<<('t' - 'a'));

  for(int i=0; i<word_num ; ++i){
    cin>>temp;
    words_bits[i] =start_bit;

    for(int idx =4 ; idx<(temp.size() - 4 ); ++idx)
      words_bits[i] = words_bits[i] | (1<<(temp[idx] - 'a'));
  }

  if(learned_num <5){
    cout<<0<<'\n';
    return 0;
  }

  int bit_cnt =0,max_word = 0, pos_word_cnt=0;

  for(int bits = start_bit ; bits  <= MAX_BIT ; ++bits){
    if((bits & start_bit) != start_bit)
      continue;

    pos_word_cnt = bit_cnt = 0;
    for(int i=1; i<= MAX_BIT  ; i = i<<1){
      if(bits & i)
        ++bit_cnt;
    }

    if(bit_cnt == learned_num ){
      for(int i=0; i<word_num ; ++i)
        if((words_bits[i] & bits) == words_bits[i])
          ++pos_word_cnt;
      
      max_word = max(max_word, pos_word_cnt);
    }
  }

  cout<<max_word<<'\n';
  return 0;
}
