//https://algospot.com/judge/problem/read/LIS
#include <iostream>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);

  int test_num;
  int arr_size,max_length;
  int arr[500];
  int dp[500];
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>arr_size;
    for(int j=0; j<arr_size ; ++j)
      cin>>arr[j];

    max_length =0;
    for(int idx=arr_size-1; idx>=0 ; --idx){
      dp[idx] =1;   //자기 자신만을 포함하는 경우가 있기 때문에 최솟값은 1
      for(int next_idx = idx+1; next_idx<arr_size ; ++next_idx )
        if(arr[idx] < arr[next_idx])
          dp[idx] = max(dp[idx], dp[next_idx]+1);
      
      max_length = max(max_length, dp[idx]);
    }

    cout<<max_length<<'\n';
  }

  return 0;
}
