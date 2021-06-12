//https://www.acmicpc.net/problem/1017
#include<iostream>
#include<queue>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 2001;
bool is_prime[MAXN+1];
int arr_size;
vector<int> a_set, b_set;
vector<vector<int>> adj;
vector<int> a_match, b_match, visited;

void SieveEratos(){
  memset(is_prime, true, sizeof(is_prime));
  int sqrtn = int(sqrt(MAXN));

  is_prime[0] = is_prime[1] = false;
  for(int i=2; i<=sqrtn ; ++i){
    if(is_prime[i])
      for(int j= i*i ; j<=MAXN ; j+= i)
        is_prime[j] = false;
  }
}

bool DFS(int a_idx){
  //a가 첫번째 수라면 이미 다른 수와 연결되어 있음
  if(a_idx == 0 || visited[a_idx])
    return false;
  visited[a_idx] = true;

  for(int i=0; i<adj[a_idx].size() ; ++i){
    int b_idx = adj[a_idx][i];

    if(b_match[b_idx] == -1 || DFS(b_match[b_idx])){
      a_match[a_idx] = b_idx;
      b_match[b_idx] = a_idx;
      return true;
    }
  }
  
  return false;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin>>arr_size;

  int first_num;
  cin>>first_num;

  bool is_first_even;
  is_first_even = first_num%2 ==0 ? true : false;
  a_set.push_back(first_num);

  int temp;
  for(int i=1; i<arr_size ; ++i){
    cin>>temp;

    //첫수가 짝수라면 홀수와만 소수를 만들 수 있음
    if(is_first_even){
      if(temp %2 == 0)
        a_set.push_back(temp);
      else 
        b_set.push_back(temp);
    }else{
      if(temp %2 != 0)
        a_set.push_back(temp);
      else 
        b_set.push_back(temp);
    }
  }

  //애초에 짝수와 홀수의 개수가 맞지 않는 경우
  if(b_set.size() != a_set.size()){
    cout<<-1<<'\n';
    return 0;
  }

  //에라토스테네스의 체
  SieveEratos();

  //a 집합의 수들과 소수를 이루는 b 집합의 수를 연결
  adj = vector<vector<int>>(a_set.size());
  for(int i=0; i<a_set.size() ; ++i)
    for(int j=0; j<b_set.size() ; ++j)
      if(is_prime[a_set[i]+b_set[j]])
        adj[i].push_back(j);


  vector<int> answers;
  for(int i=0; i<adj[0].size(); ++i){
    int pair_b_idx = adj[0][i];
    int paired_size =1;

    a_match = vector<int>(a_set.size(), -1);
    b_match = vector<int>(b_set.size(), -1);
    
    //첫번째 수와 미리 연결해주자.
    a_match[0] = pair_b_idx;
    b_match[pair_b_idx] = 0;

    for(int j =1 ; j<a_set.size() ; ++j){
      visited = vector<int>(a_set.size(), false);
      if(DFS(j))
        paired_size++;
    }

    if(paired_size == b_set.size())
      answers.push_back(b_set[pair_b_idx]);
  }

  if(answers.size() != 0){
    sort(answers.begin(), answers.end());
    for(int i=0; i<answers.size() ; ++i)
      cout<<answers[i]<<' ';
  }else
    cout<<-1;
  
  cout<<'\n';
  
  return 0;
}
