//https://algospot.com/judge/problem/read/HANOI4
#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
using namespace std;

typedef unsigned long long ull;
int discus_num;

int Sign(const int& x){
  if(!x) 
    return 0;
  return x > 0 ? 1 : -1;
} 

int IncrAbsolute(const int& x){
  if(x < 0)
    return x - 1;
  return x +1;
}

vector<ull> MoveDiscus(const ull& state){
  vector<ull> ret;
  ull column_state=0;

  int columns_top[4] = {discus_num,discus_num,discus_num,discus_num}; //빈 기둥은 모든 원반이 들어갈 수 있도록 원반의 크기보다 크게
  for(int col_idx=0; col_idx<4 ; ++col_idx){
    column_state = state >>(col_idx*discus_num);
    for(int discus_size=0; discus_size < discus_num; ++discus_size)
      if(column_state & (ull)1<<discus_size){
        columns_top[col_idx] = discus_size;
        break;
      }
  }
  
  for(int col_idx=0; col_idx<4 ; ++col_idx){
    for(int dest_col =0; dest_col<4 ; ++dest_col){
      if(columns_top[dest_col] > columns_top[col_idx]){  //이동이 가능한 경우
        ull new_state = state;
        new_state ^= ((ull)1 << columns_top[col_idx])<<(col_idx*discus_num);
        new_state |= ((ull)1 << columns_top[col_idx])<<(dest_col*discus_num);
        ret.push_back(new_state);
      }
    }
  }
  return ret;
}

int SolveHanoi4(const ull& start_state , const ull& dest_state){
  map<ull, int> visited;
  queue<ull> que;

  if(start_state == dest_state) return 0;

  que.push(start_state);
  que.push(dest_state);
  visited[start_state] = 1;
  visited[dest_state] = -1;

  ull now_state;
  int visited_order;
  while(1){
    now_state = que.front();
    que.pop();
    visited_order = visited[now_state];

    vector<ull> changed_state = MoveDiscus(now_state);

    for(int i=0; i<changed_state.size() ; ++i){
      if(visited.count(changed_state[i])==0){ //아직 방문하지 않은 경우
        que.push(changed_state[i]);
        visited[changed_state[i]] = IncrAbsolute(visited_order);
      }else if(Sign(visited_order) != Sign(visited[changed_state[i]]) ){
        return abs(visited_order) + abs(visited[changed_state[i]]) -1;
      }
    }
  }
  return -1; //불가능한 경우
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>discus_num;
    ull start_state = 0;

    int num, discus_size;
    for(int col_idx=0; col_idx<4 ; ++col_idx){
      cin>>num;

      ull column_state = 0;
      for(int i =0; i<num ; ++i){
        cin>>discus_size;
        column_state |= ((ull)1<<(discus_size-1));
      }

      start_state |= (column_state<<(col_idx*discus_num));
    }

    ull dest_state=0;
    for(int i=0; i<discus_num ; ++i)
      dest_state |= (ull)1<<i;
    
    dest_state = dest_state <<(3*discus_num);

    cout<<SolveHanoi4(start_state,dest_state)<<'\n';
  }

  return 0;
}
