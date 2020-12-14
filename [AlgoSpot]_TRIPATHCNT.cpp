//https://algospot.com/judge/problem/read/TRIPATHCNT
#include <iostream>
#include <string.h>
using namespace std;

int tri_size;
int triangle[100][100];
int cache_path[100][100];
int cache_max[100][100];

int TriPathCnt(int r,int c){
  if(r==tri_size-1)
    return 1;

  int& ret = cache_path[r][c];
  if(ret != -1)
    return ret;

  if(cache_max[r+1][c] > cache_max[r+1][c+1])
    ret = TriPathCnt(r+1, c);
  else if(cache_max[r+1][c] < cache_max[r+1][c+1])
    ret = TriPathCnt(r+1, c+1);
  else
    ret = TriPathCnt(r+1, c) + TriPathCnt(r+1, c+1);
    
  return ret;
}

int TriMaxSum(int r,int c){
  int& ret = cache_max[r][c];
  if(r == tri_size -1)
    return ret= triangle[r][c];

  if(ret != -1)
    return ret;

  ret = triangle[r][c]+ max(TriMaxSum(r+1 , c), TriMaxSum(r+1, c+1));
  return  ret;
}

int main() {
  ios_base::sync_with_stdio(0);

  int test_num;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>tri_size;

    for(int r=0; r<tri_size ; ++r)
      for(int c=0; c<=r ; ++c)
        cin>>triangle[r][c];
      
    memset(cache_max, -1,sizeof(cache_max));
    TriMaxSum(0, 0);

    memset(cache_path, -1, sizeof(cache_path));
    cout<<TriPathCnt(0, 0)<<'\n';
  }

  return 0;
}
