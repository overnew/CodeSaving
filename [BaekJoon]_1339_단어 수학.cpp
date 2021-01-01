//https://www.acmicpc.net/problem/1339
#include <iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int word_num;
string word_arr[10];
int appearance_count[26][8];
pair<int, int> priority[26];
int number_setting[26];

int main() {
  //ios_base::sync_with_stdio(0);

  cin>>word_num;

  for(int i=0; i<word_num ; ++i)
    cin>>word_arr[i];

  int alpabet,order;  
  memset(appearance_count, 0, sizeof(appearance_count));

  for(int i=0; i<word_num; ++i){
    order =0;
    for(int idx= word_arr[i].length()-1 ;  idx>=0 ; --idx){
      alpabet = word_arr[i][idx]- 'A';
      ++appearance_count[alpabet][order++];
    }
  }

  for(int i=0; i<26 ; ++i){
    priority[i].first = 0;
    priority[i].second = i;
    for(int order=7; order>=0 ; --order){
      priority[i].first += appearance_count[i][order];
      priority[i].first *= 10;
    }
  }

  sort(priority,priority+26,greater());

  int number=9;
  for(int i=0; i<10 ; ++i){
    number_setting[priority[i].second] = number;
    --number;
  }

  int convert_num,sum=0;
  for(int i=0; i<word_num ; ++i){
    convert_num =0;
    for(int idx=0; idx<word_arr[i].length() ; ++idx){
      convert_num += number_setting[word_arr[i][idx]- 'A'];
      if(idx<word_arr[i].length()-1)
        convert_num *= 10;
    }
    sum += convert_num;
  }

  cout<<sum<<'\n';
  return 0;
}
