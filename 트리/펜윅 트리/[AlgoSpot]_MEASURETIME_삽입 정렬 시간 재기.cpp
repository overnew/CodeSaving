//https://www.algospot.com/judge/problem/read/MEASURETIME
#include<vector>
#include<cstdio>
using namespace std;

typedef long long ll;

class FenwickTree{
  public:
  vector<ll> tree = vector<ll>(1000001);

  ll Sum(int pos){
    ll ret = 0;
    while(pos>0){
      ret += tree[pos];
      pos &= (pos -1);
    }
    return ret;
  }

  void Add(int pos){
    while(pos <= tree.size()){
      tree[pos] += 1;
      pos += (pos & -pos);
    }
  }
};

int main(){
  int test_num,arr_size;
  scanf("%d", &test_num);
  
  while(test_num--){
    scanf("%d", &arr_size);
    FenwickTree fen_tree;
    
    int num;
    long long result =0;
    for(int i =0; i<arr_size ; ++i){
      scanf("%d", &num);
      ++num;
      result += fen_tree.Sum(1000000) - fen_tree.Sum(num);
      fen_tree.Add(num);
    }
    printf("%lld\n", result);
  }

  return 0;
}
