//
#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<cmath>
using namespace std;

int words_num;
int adj[26][26];
int out_degree[26];
int in_degree[26];

void WordChainDFS(queue<int>& que ,int idx){
  for(int i=0; i<26 ; ++i){
    if(adj[idx][i] !=0){
      --adj[idx][i];
      WordChainDFS(que,i);
    }
  }
  que.push(idx);
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  string temp;
  int start_alphabet, end_alphabet;
  while(test_num--){
    vector<vector<vector<string>>> words_list(26, vector<vector<string>>(26));
    memset(adj, 0, sizeof(adj));
    memset(out_degree, 0, sizeof(out_degree));
    memset(in_degree, 0, sizeof(in_degree));

    cin>>words_num;
    for(int i=0; i<words_num ; ++i){
      cin>>temp;
      start_alphabet = temp[0]-'a';
      end_alphabet = temp[temp.size()-1]-'a';
      adj[start_alphabet][end_alphabet]++;
      out_degree[start_alphabet]++;
      in_degree[end_alphabet]++;
      words_list[start_alphabet][end_alphabet].push_back(temp);
    }

    bool is_possible = true;
    int pos_start_cnt=0, pos_end_cnt=0;
    for(int i=0; i<26 ; ++i){
      if(abs(out_degree[i]-in_degree[i]) == 1){
        if(out_degree[i]-in_degree[i] == 1){  //start node가 가능한 경우
          start_alphabet = i;
          if(++pos_start_cnt >1){
            is_possible = false;
            break;
          }
        }else{
          if(++pos_end_cnt >1){
            is_possible = false;
            break;
          }
        }
      }else if(abs(out_degree[i]-in_degree[i]) > 1){  //불가능한 그래프
        is_possible = false;
        break;
      }
    }

    if( (pos_start_cnt == 1 && pos_end_cnt== 0) || (pos_start_cnt == 0 && pos_end_cnt== 1))
      is_possible = false;

    if(!is_possible ){
      cout<<"IMPOSSIBLE"<<"\n";
      continue;
    }

    queue<int> chain_que;
    WordChainDFS(chain_que, start_alphabet);

    vector<string> answer;
    while(1){
      end_alphabet = chain_que.front();
      chain_que.pop();
      if(chain_que.empty())
        break;
      
      start_alphabet = chain_que.front();
      answer.push_back(words_list[start_alphabet][end_alphabet].back());
      words_list[start_alphabet][end_alphabet].pop_back();
    }

    for(int i=words_num-1; i>=0 ; --i)
      cout<<answer[i]<<' ';
    
    cout<<'\n';
  }

  return 0;
}
