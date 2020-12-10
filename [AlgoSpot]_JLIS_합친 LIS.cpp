//https://algospot.com/judge/problem/read/JLIS
#include <iostream>
#include<string.h>
using namespace std;

int a_length,b_length;
int arr_a[101],arr_b[101];
int dp[101][101];
const long long min_value = INT64_MIN;

int findJLIS(int idx_a, int idx_b){
  int& ret = dp[idx_a][idx_b];
  if(ret != -1)
    return ret;

  long long max_value;
  if(idx_a == 0 && idx_b == 0)
    max_value = min_value;
  else
   max_value= max(arr_a[idx_a], arr_b[idx_b]);
  
  int max_jlis=0;
  for(int next_idx_a=idx_a+1; next_idx_a<=a_length ; ++next_idx_a)
    if(max_value < arr_a[next_idx_a])
      max_jlis = max(max_jlis, 1+ findJLIS(next_idx_a,idx_b));
  
  for(int next_idx_b=idx_b+1; next_idx_b<=b_length ; ++next_idx_b)
    if(max_value < arr_b[next_idx_b])
      max_jlis = max(max_jlis, 1+ findJLIS(idx_a,next_idx_b));
  
  ret = max_jlis;
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  int test_num;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>a_length>>b_length;
    
    arr_a[0] = INT32_MIN;
    for(int j=1; j<=a_length ; ++j)
      cin>>arr_a[j];

    arr_b[0] = INT32_MIN;
    for(int j=1; j<=b_length ; ++j)
      cin>>arr_b[j];
    
    memset(dp, -1, sizeof(dp));

    cout<<findJLIS(0, 0)<<'\n';
  }

  return 0;
}
