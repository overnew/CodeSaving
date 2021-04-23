//https://algospot.com/judge/problem/read/CHILDRENDAY
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int Append(int here, int edge, int mod){
  int there = here*10 + edge;
  if(there >=mod)
    return mod + there %mod;  // n이상의 경우는 mod를 더해 주어 표현해 n이하와 구분하자
  return there % mod;
}

string Gifts(const string& digit_str, int children_num,int greedy_num){
  vector<int> digit_list(digit_str.size());

  for(int i=0; i<digit_str.size() ; ++i)
    digit_list[i] = digit_str[i] - '0';

  sort(digit_list.begin(), digit_list.end());

  vector<int> parent(2*children_num, -1), choice(2*children_num, -1);
  queue<int> que;

  parent[0] = 0;
  que.push(0);

  int here,there;
  while(!que.empty()){
    here = que.front();
    que.pop();

    for(int i=0; i<digit_list.size() ; ++i){
      there = Append(here , digit_list[i], children_num);

      if(parent[there] == -1){
        parent[there] = here;
        choice[there] = digit_list[i];
        que.push(there);
      }
    }

  }

  if(parent[children_num+ greedy_num] == -1)  // 정답에 도달하지 못한 경우
    return "IMPOSSIBLE";

  string ret;
  here = children_num+ greedy_num;
  while(parent[here] != here){  //0으로 도달하여 끝난 경우
    ret += char('0' + choice[here]);
    here = parent[here];
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    string digits;
    int children_num, greedy_num;
    cin>>digits>>children_num>>greedy_num;

    cout<<Gifts(digits, children_num, greedy_num)<<"\n";
  }

  return 0;
}
