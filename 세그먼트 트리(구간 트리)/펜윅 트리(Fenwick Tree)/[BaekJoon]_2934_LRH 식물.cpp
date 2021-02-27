//https://www.acmicpc.net/problem/2934
#include<vector>
#include<cstdio>
using namespace std;

const int TREESIZE = 100001;

class FenwickTree{
  public:
  vector<int> tree = vector<int>(TREESIZE);  

  int Sum(int idx){
    int ret = 0;
    while(idx>0){
      ret += tree[idx];
      idx &= (idx -1);
    }
    return ret;
  }

  void Update(int idx, int x){
    while(idx <= tree.size()){
      tree[idx] += x;
      idx += (idx & -idx);
    }
  }
};

int main(){
  int days;
  scanf("%d", &days);

  FenwickTree tree;
  int L,R,left_flower, right_flower;
  for(int i=0; i<days ; ++i){
    scanf("%d %d",&L, &R);
    left_flower = tree.Sum(L);
    right_flower = tree.Sum(R);
    printf("%d\n",left_flower + right_flower);
    tree.Update( L, -left_flower);
    tree.Update( L+1, left_flower+1);
    tree.Update( R, -right_flower -1);
    tree.Update( R+1, right_flower );
  }

  return 0;
}
