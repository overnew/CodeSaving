const int TREESIZE = 1000001;

class LazyFenwickTree{
  public:
  vector<int> degree_tree = vector<int>(TREESIZE);  //일차항 저장
  vector<int> const_tree = vector<int>(TREESIZE);   //상수항 저장

  void RangeUpdate(int L, int R, int x){
    Update(degree_tree, L, x);    //B[L] += x로 update
    Update(degree_tree, R+1, -x); //B[R+1] -= x로 update

    Update(const_tree, L, (-L + 1)*x);
    Update(const_tree, R+1, (R)*x);
  }

  int RangeSum(int L, int R){
    int ret = Sum(degree_tree,R)*R + Sum(const_tree,R); //[1,R]의 구간합
    return ret -= Sum(degree_tree,L-1)*(L-1) + Sum(const_tree,L-1); //[1,L-1]의 구간합
  }

  int Sum(vector<int>& tree,int idx){
    int ret = 0;
    while(idx>0){
      ret += tree[idx];
      idx &= (idx -1);
    }
    return ret;
  }

  void Update(vector<int>& tree, int idx, int x){
    while(idx <= tree.size()){
      tree[idx] += x;
      idx += (idx & -idx);
    }
  }
};
