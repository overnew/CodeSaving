//https://www.acmicpc.net/problem/2805
#include <iostream>
#include<vector>
using namespace std;

int tree_num;
long long need_len;
vector<int> tree_height;

int main() {
  ios_base::sync_with_stdio(0);
  cin>>tree_num>>need_len;

  int temp,left= 0,right=0;
  for(int i=0; i<tree_num ; ++i){
    cin>>temp;
    tree_height.push_back(temp);
    right = max(right, temp);
  }

  long long cut_sum=0;
  int mid,answer=0;
  while(left<= right){
    cut_sum=0;
    mid = (left +right) /2;

    for(int i=0; i<tree_num ; ++i){
      if(tree_height[i] >mid)
        cut_sum += (long long)(tree_height[i] - mid);
    }

    if(cut_sum < need_len){
      right = mid -1;
    }else{
      left = mid +1;
      if(answer < mid)
        answer = mid; 
    }
  }

  cout<<answer<<'\n';
  return 0;
}
