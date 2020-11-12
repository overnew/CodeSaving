//https://www.acmicpc.net/problem/5557
#include <iostream>
using namespace std;

int N;
int number_set[100];
long long dp[21] ={0,};

long long lowerGradeMath(int idx){
  if(idx >= N-1)
    return dp[number_set[N-1]];

  long long temp[21] ={0,};

  int next_num;
  for(int num=0; num<=20 ; ++num)
    if(dp[num] >  0){
      
      next_num = num - number_set[idx];
      if(next_num >=0)  //빼는 경우는 0과 같거나 크면 됨
        temp[next_num] += dp[num];

      next_num = num + number_set[idx];
      if(next_num <=20) //더하는 경우는 20과 같거나 작으면 됨
        temp[next_num] += dp[num];
    }

  for(int i=0; i<=20 ;++i)
    dp[i] = temp[i];

  return lowerGradeMath(idx+1);
}

int main() { 
  cin>>N;

  for(int i=0; i<N ; ++i)
    cin>>number_set[i];
  dp[number_set[0]] = 1;

  cout<<lowerGradeMath(1)<<'\n';

  return 0;
}
