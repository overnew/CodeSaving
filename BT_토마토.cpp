//https://www.acmicpc.net/problem/7576//

#include <iostream>
#include <queue>
using namespace std;

int N,M;
int now_cnt=0;
int next_cnt=0;
int arr[1000][1000];
queue<pair<int, int>> q; //bfs용 큐
int ch_r[4] ={ 1, 0,-1,0};
int ch_c[4] ={0 ,1 ,0,-1};

int ripenTomatos(){
  int now_r,now_c,next_r, next_c;
  int days=0;

  while(!q.empty()){
    now_r= q.front().first;
    now_c =q.front().second;
    q.pop();
    --now_cnt; //지금 익은 토마토 개수를 한 개씩 줄여줌

    for(int i=0; i<4 ; ++i){
      next_r = now_r + ch_r[i];
      next_c = now_c +ch_c[i];

      if(0 <=next_r&& next_r <N && 0<= next_c && next_c <M) //범위 검사
        if( arr[next_r][next_c] ==0 ){
          q.push(make_pair(next_r, next_c));
          arr[next_r][next_c] = 1;
          ++next_cnt; //하루 후 익은 토마토 개수를 증가
        }
      
    }

    if(now_cnt == 0){// 지금 익은 토마토 모두 확인시
      ++days;
      now_cnt = next_cnt;
      next_cnt=0;
    }
    
  }
  
  for(int i=0; i<N ; ++i)
    for(int j=0; j<M ; ++j)
      if(arr[i][j] == 0)
        return -1;

  return days-1; //더 익게할 토마토가 없는 경우에도 days가 +1되므로 -1해줌

}

int ripenDays(){
  for(int i=0; i<N ; ++i)
    for(int j=0; j<M ; ++j)
      if(arr[i][j] == 1){ //익은 토마토는 미리 큐에 삽입
        q.push(make_pair(i, j));
        ++now_cnt;  //익은 토마토의 개수를 세준다.
      }

  return ripenTomatos();
}


int main() {
  ios_base::sync_with_stdio(0);
  
  cin>>M>>N;

  for(int i=0; i<N; ++i)
    for(int j=0; j<M ; ++j)
      cin>>arr[i][j];
        
  cout<<ripenDays()<<'\n';
  return 0;
}
