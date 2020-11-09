//https://algospot.com/judge/problem/read/WILDCARD
#include <iostream>
#include<string>
#include<vector>
#include<string.h>
#include <algorithm>
using namespace std;

int file_num;
string wild_card;
string file_name;
int cache[101][101];

int matchWildCard(int wild_idx, int file_idx){
  int& ret = cache[wild_idx][file_idx];
  if(ret != -1)
    return ret;

  while((wild_card[wild_idx] == file_name[file_idx] || wild_card[wild_idx]=='?') && wild_idx <wild_card.length() && file_idx<file_name.length()){
    ++wild_idx;
    ++file_idx;
  }

  if(wild_idx == wild_card.length() &&file_idx ==file_name.length()){
    ret =1;
    return ret;  
  }
  ret =0;

  if(wild_card[wild_idx] =='*')
    for(int next_file_idx=file_idx; next_file_idx<=file_name.length() ; ++next_file_idx)
      if(matchWildCard(wild_idx+1, next_file_idx)==1){
        ret = 1;
        break;
      }

  return ret;
}

int main() { 
  int test_num;
  string temp;
  cin>>test_num;
  
  for(int i=0; i<test_num ; ++i){
    vector<string> matching_names;
    cin>>wild_card>>file_num;

    for(int j=0; j<file_num ; ++j){
      cin>>file_name;
      memset(cache, -1, sizeof(cache));
      
      if(matchWildCard(0, 0) == 1)
        matching_names.push_back(file_name);
    }
    
    sort(matching_names.begin(),matching_names.end());

    vector<string>::iterator it;
    for(it = matching_names.begin(); it<matching_names.end() ; ++it)
      cout<<*it<<'\n';
    
  }

  return 0;
}
