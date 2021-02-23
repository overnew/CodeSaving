//https://algospot.com/judge/problem/read/FAMILYTREE
#include<vector>
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

const int MAX_N = 100000;
vector<vector<int>> child;

int no2serial[MAX_N], serial2no[MAX_N];
int locInTrip[MAX_N], depth[MAX_N];

vector<int> trip;
vector<int> segment_tree;
int nextSerial;

int Init(int left, int right, int node){
  if(left == right)
    return segment_tree[node] = trip[left];
  
  int mid = (left + right)/2;
  return segment_tree[node] = min(Init(left, mid, node*2), Init(mid+1, right, node*2 +1));  
}

int Query(int left, int right, int query_left, int query_right, int node){
  if(right < query_left || query_right < left)
    return INT32_MAX;
  
  if(query_left<=left && right <= query_right)
    return segment_tree[node];
  
  int mid = (left + right)/2;
  return min( Query(left, mid, query_left, query_right, node * 2), Query(mid+1, right, query_left, query_right, node * 2 + 1) );
}

void Traverse(int here, int d ){
  no2serial[here] = nextSerial;
  serial2no[nextSerial] = here;
  ++nextSerial;
  depth[here] = d;

  locInTrip[here] = trip.size();
  trip.push_back(no2serial[here]);

  for(int i=0; i<child[here].size() ; ++i){
    Traverse(child[here][i] , d+1);
    trip.push_back(no2serial[here]);
  }

}

int main(){
  int test_num,family_num,Q;
  scanf("%d", &test_num);

  while(test_num--){
    scanf("%d %d", &family_num, &Q);
    child.clear();
    child = vector<vector<int>>(MAX_N);
    int parent;
    for(int i=1; i< family_num; ++i){
      scanf("%d", &parent );
      child[parent].push_back(i);
    }
    nextSerial=0;
    Traverse(0 , 0);
    int tree_hight = (int)ceil(log2(trip.size()));
    segment_tree.clear();
    segment_tree = vector<int>(1<<(tree_hight + 1));
    Init(0, trip.size()-1, 1);

    int a,b, lca, query_left, query_right;
    
    while(Q--){
      scanf("%d %d", &a, &b);
      query_left = locInTrip[a];
      query_right = locInTrip[b];
      if(query_left > query_right)
        swap(query_left,query_right);

      lca = serial2no[ Query(0, trip.size()-1, query_left, query_right, 1)];
      printf("%d\n", depth[a] + depth[b] - 2*depth[lca] );
    }
    
  }

  return 0;
}
