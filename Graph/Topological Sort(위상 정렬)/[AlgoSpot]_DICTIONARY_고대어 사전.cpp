//https://algospot.com/judge/problem/read/DICTIONARY
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int word_num;
vector<string> dictionary;
bool alphabet_connection[26][26]; //directed edge
vector<int> alphabet_order;
bool visited[26];

void TopologyDFS(int idx){
  visited[idx] = true;

  for(int i =0; i<26 ; ++i){
    if(alphabet_connection[idx][i] && !visited[i]){
      TopologyDFS(i);
    }
  }
  alphabet_order.push_back(idx);
}

int main(){
  int test_num;
  cin>>test_num;

  bool is_possible = true;
  while(test_num--){
    cin>>word_num;
    
  memset(alphabet_connection, false, sizeof(alphabet_connection));
  memset(visited, false, sizeof(visited));
  is_possible = true;
  dictionary.clear();
  alphabet_order.clear();

  string temp;
  for(int i = 0; i<word_num ; ++i){
    cin>>temp;
    dictionary.push_back(temp);
  }

  int min_len;
  for(int idx=0; idx<word_num-1 ; ++idx){
    min_len = min(dictionary[idx].size() , dictionary[idx+1].size());
    for(int len =0; len<min_len ;++len){
        if(dictionary[idx][len] != dictionary[idx+1][len]){
          alphabet_connection[dictionary[idx][len] - 'a'][dictionary[idx+1][len] - 'a'] = true;
          break;
        }
    }
  }


  for(int i=0; i<26 ; ++i){ 
    if(!visited[i])
      TopologyDFS(i);
  }


  for(int i=0; i<alphabet_order.size() ; ++i ){
    for(int j= i+1; j<alphabet_order.size() ; ++j){
      if(alphabet_connection[alphabet_order[i]][alphabet_order[j]]){  //역순이 존재해 DAG가 아닌 경우
        cout<<"INVALID HYPOTHESIS\n";
        is_possible = false;
        break;
      }
    }
    if(!is_possible)
      break;
  }

  if(!is_possible)
    continue; 

  reverse(alphabet_order.begin(),alphabet_order.end());
  for(int i=0; i<alphabet_order.size() ; ++i){
    cout<<(char)(alphabet_order[i]+'a');
  }
  cout<<'\n';
  }
  
  return 0;
}
