//https://www.acmicpc.net/problem/10942
#include <iostream>
#include<string.h>
using namespace std;

int arr_size;
int arr[2001];
int question_num;
bool dp[2001][2001];
bool qna[1000000];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>arr_size;

  for(int i=1; i<=arr_size ; ++i)
    cin>>arr[i];

  memset(dp, false, sizeof(dp));
  for(int i=0; i<=arr_size ; ++i)
    dp[i][i] = true;

  for(int end=2; end<=arr_size ; ++end)
    for(int start=1; start<end ; ++start)
      if(arr[start] == arr[end]){
        if(end - start >=2)
          dp[start][end] = dp[start+1][end-1];
        else 
          dp[start][end] = true;
      }
      
  cin>>question_num;

  int start, end;
  for(int i=0; i<question_num ; ++i){
    cin>>start>>end;
    qna[i] = dp[start][end];
  }

  for(int i=0; i<question_num ; ++i)
    cout<<qna[i]<<'\n';

  
