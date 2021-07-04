//https://www.acmicpc.net/problem/11066
#include<iostream>
#include<string.h>
using namespace std;

const int INF = 987654321;
int file_num;
int files_size[501];
int dp[501][501];
int arr_sum[501];

int MinCostDFS(int start, int end){
  if(start == end)
    return files_size[start];
    
  int& ret = dp[start][end];
  if(ret != -1)
    return ret;
  
  ret = INF;
  for(int idx = start; idx< end ; ++idx)
    ret = min(ret, MinCostDFS(start, idx) + MinCostDFS(idx+1, end));
  
  //구한 값에 이번 파일의 크기 더해주기
  ret += arr_sum[end] - arr_sum[start -1];
  return ret;  
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>file_num;
    memset(dp, -1 ,sizeof(dp));
    memset(arr_sum, 0, sizeof(arr_sum));

    for(int i=1; i<=file_num ; ++i){
      cin>>files_size[i];
      //구간 합 만들어 주기
      arr_sum[i] = files_size[i] + arr_sum[i-1];
    }

    cout<<MinCostDFS(1, file_num) - arr_sum[file_num]<<'\n';
  }

  return 0;
}
