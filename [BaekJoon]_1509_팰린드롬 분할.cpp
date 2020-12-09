//https://www.acmicpc.net/problem/1509
#include <iostream>
#include<string>
#include<string.h>
using namespace std;

string arr;
bool is_palin[2501][2501];
int dp[2501];

int main() {
  ios_base :: sync_with_stdio(false);
  cin>>arr;
  arr = "+" + arr;

  memset(is_palin, false, sizeof(is_palin));

  for(int i=0; i<arr.length() ; ++i)
    is_palin[i][i] = true;

  for(int end =2; end<arr.length() ; ++end)
    for(int start = 1 ; start<end ; ++start)
      if(arr[start] == arr[end]){
        if(end - start >=2)
          is_palin[start][end] = is_palin[start+1][end-1];
        else
          is_palin[start][end] = true;
      }

  dp[0] = 0;
  dp[1] = 1;
  int min_palin;
  for(int i =2; i<arr.length() ; ++i){
    min_palin = 2500;
    for(int j = 0 ; j<i ; ++j)
      if(is_palin[j+1][i])
        min_palin = min(min_palin,dp[j] + 1);
    
    dp[i] = min_palin;
  }  
  
  cout<<dp[arr.length()-1]<<'\n';
  return 0;
}
