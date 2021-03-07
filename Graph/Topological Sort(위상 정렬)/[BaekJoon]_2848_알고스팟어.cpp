//https://www.acmicpc.net/problem/2848
#include<iostream>
#include<string>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int word_num,used_alphabet_num =0;
vector<string> dictionary;
vector<int> adj[26]; //directed edge
vector<int> alphabet_order;
bool visited[26];
int indegree[26];

int main(){
  cin>>word_num;
  memset(visited, false, sizeof(visited));
  memset(indegree, 0, sizeof(indegree));

  string temp;
  for(int i = 0; i<word_num ; ++i){
    cin>>temp;
    dictionary.push_back(temp);
    for(int j=0; j<temp.size() ; ++j){
      if(!visited[temp[j]-'a']){
        visited[temp[j]-'a'] = true;
        used_alphabet_num++;
      }
    }
  }

  bool is_possible = true;
  int min_len;
  for(int idx=0; idx<word_num-1 ; ++idx){
    min_len = min(dictionary[idx].size() , dictionary[idx+1].size());
    for(int len =0; len<dictionary[idx].size() ;++len){

      if(len < dictionary[idx+1].size()){
        if(dictionary[idx][len] != dictionary[idx+1][len]){
          adj[dictionary[idx][len] - 'a'].push_back(dictionary[idx+1][len] - 'a');
          indegree[dictionary[idx+1][len] - 'a']++;
          break;
        }
      }else{
        is_possible = false;
        break;
      }
    }
  }  

  queue<int> que; //들어오는 간선(edge)이 없는 경우만 넣는 큐
  for(int i=0; i<26 ; ++i){
    if(visited[i]) //사용된 알파벳에서만
    if(indegree[i] == 0)
      que.push(i);
  }

  bool is_single_order = true;
  int alphabet_idx;
  for(int i =0; i<used_alphabet_num ; ++i){
    if(que.empty()){//for문을 다 돌기전에 큐가 비었다면 역방향이 있다는 것
      is_possible = false;
      break;
    }

    alphabet_idx = que.front();
    que.pop();

    if(que.size() >=1)
      is_single_order = false;  //순서가 여러개면 저장할 필요x
    else
      alphabet_order.push_back(alphabet_idx);

    for(int j=0; j<adj[alphabet_idx].size() ; ++j){
      if(--indegree[adj[alphabet_idx][j]] == 0)
        que.push(adj[alphabet_idx][j]);
    }
    
  }

  if(!is_possible){
    cout<<"!\n";
  }else if(is_single_order){
    for(int i=0; i<alphabet_order.size() ; ++i)
       cout<<(char)(alphabet_order[i]+'a');
    cout<<'\n';
  }else{
    cout<<"?\n";
  }

  return 0;
}
