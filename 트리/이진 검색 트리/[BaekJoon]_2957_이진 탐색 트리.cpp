//https://www.acmicpc.net/problem/2957
#include<map>
#include<cstdio>
using namespace std;

int main(){
  int arr_size,x;
  
  map<int, long long> tree;
  map<int, long long>::iterator low_it, up_it;
  long long dep, counter =0;
  tree.insert(make_pair(0,-1));
  tree.insert(make_pair(300001,-1)); 

  scanf("%d", &arr_size);
  for(int i=0; i<arr_size ; ++i){
    scanf("%d", &x);
    up_it = tree.upper_bound(x);
    low_it = up_it;
    --low_it;

    dep = max(low_it->second, up_it->second) + 1;
    tree.insert(make_pair(x,dep));
    
    counter += dep;
    printf("%lld\n",counter);
  }

  return 0;
}
