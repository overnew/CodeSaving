//https://www.acmicpc.net/problem/13398
#include <iostream>
using namespace std;

int arr_size;
int dp[100000][2];

int main() {
  ios_base :: sync_with_stdio(false);

  cin>>arr_size;

  int temp_num;

  cin>>dp[0][0];
  dp[0][1] = dp[0][0];
  
  int max_num =dp[0][0];

  for(int i=1; i<arr_size ; ++i){
    cin>>temp_num;
    dp[i][0] = max(dp[i-1][0] + temp_num, temp_num);
    dp[i][1] = max(dp[i-1][0], dp[i-1][1]+ temp_num);

    max_num =max(max_num,max(dp[i][0], dp[i][1]));
  }

  cout<<max_num<<'\n';
  return 0;
}
