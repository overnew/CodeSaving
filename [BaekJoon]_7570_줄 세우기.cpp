//https://www.acmicpc.net/problem/7570
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int idx_to_num[1000001];
  int num_to_pos[1000001];
  int sequence_cache[1000001];
  int children_num;
  cin>> children_num;

  for(int i=0; i<children_num ; ++i){
    cin>>idx_to_num[i];
    num_to_pos[idx_to_num[i]] = i;
  }

  int max_sequence_len=1;
  for(int idx= children_num-1; idx>=0 ; --idx){
    sequence_cache[idx] = 1;
    if(idx_to_num[idx]<children_num)
      if(idx<num_to_pos[idx_to_num[idx]+1])
        sequence_cache[idx] = sequence_cache[num_to_pos[idx_to_num[idx]+1]] +1;
       
    max_sequence_len = max(max_sequence_len,sequence_cache[idx]);
  }

  cout<<children_num - max_sequence_len<<'\n';
  return 0;
}
