//https://algospot.com/judge/problem/read/HANOI4
#include<vector>
#include<iostream>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;

int discus_num;
int visited[1<<12*2];

inline int Sign(const int& x){
  if(!x) 
    return 0;
  return x > 0 ? 1 : -1;
} 

inline int IncrAbsolute(const int& x){
  if(x < 0)
    return x - 1;
  return x +1;
}

inline int GetColumnIdx(int state, const int& size){
  return (state>>(size*2)) & 3;
}

inline int SetState(int state, int size, const int& column_idx){
  return ( ( state & ~(3<<(size*2)) ) | (column_idx<<(size*2)) );
}

int SolveHanoi4(const int& start_state , const int& dest_state){
  queue<int> que;
  memset(visited, 0 , sizeof(visited));

  if(start_state == dest_state) 
    return 0;

  que.push(start_state);
  que.push(dest_state);
  visited[start_state] = 1;
  visited[dest_state] = -1;

  int now_state;
  int visited_order;

  while(1){
    now_state = que.front();
    que.pop();
    visited_order = visited[now_state];
    
    int columns_top[4] ={discus_num, discus_num, discus_num, discus_num};

    for(int disc_size =0 ; disc_size<discus_num ;++disc_size ){
      int col_idx = GetColumnIdx(now_state, disc_size);
      columns_top[col_idx] = min(columns_top[col_idx], disc_size);
    } //기둥들의 가장 위의 원반의 크기를 구하기

    for(int col_idx =0; col_idx<4 ; ++col_idx){
      if(columns_top[col_idx] == discus_num)
        continue;

      for(int dest_col =0; dest_col<4 ; ++dest_col)
        if(columns_top[col_idx] < columns_top[dest_col]){
          int next_state = SetState(now_state,columns_top[col_idx] , dest_col );
          if(visited[next_state] == 0){ //방문하지 않은 경우
            que.push(next_state);
            visited[next_state] = IncrAbsolute(visited_order);
          }else if(Sign(visited[now_state]) != Sign(visited[next_state])){
            return abs(visited_order) + abs(visited[next_state]) -1;
          }
        }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>discus_num;
    int start_state = 0;

    int num, discus_size;
    for(int col_idx=0; col_idx<4 ; ++col_idx){
      cin>>num;
      
      for(int i =0; i<num ; ++i){
        cin>>discus_size;
        start_state = SetState(start_state,discus_size-1, col_idx);
      }
    }

    int dest_state=0;
    for(int i=0; i<discus_num ; ++i)
      dest_state = SetState(dest_state, i , 3);

    cout<<SolveHanoi4(start_state,dest_state)<<'\n';
  }

  return 0;
}
