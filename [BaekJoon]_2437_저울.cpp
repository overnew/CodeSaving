//https://www.acmicpc.net/problem/2437
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int weight_num;
int weight_list[1000];

int main() {
  ios_base::sync_with_stdio(0);
  cin>>weight_num;

  for(int i=0; i<weight_num ; ++i)
    cin>>weight_list[i];

  sort(weight_list, weight_list+weight_num);

  int end_num =0;
  int min_num = -1;
  for(int idx=0; idx<weight_num ;++idx){
    if(end_num  >= weight_list[idx] -1)
      end_num += weight_list[idx];
    else{
      min_num = end_num+1;
      break;
    }
  }

  if(min_num == -1) //for문이 break되지 않은 경우
    min_num = end_num +1;

  cout<<min_num<<'\n';
  return 0;
}
