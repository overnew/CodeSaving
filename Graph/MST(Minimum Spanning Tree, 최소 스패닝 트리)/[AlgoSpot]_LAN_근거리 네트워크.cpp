//https://algospot.com/judge/problem/read/LAN
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

int building_num, cable_num;
pair<int, int> buildings_pos[500];
vector<vector<double>> dist;
const int INF = 987654321;

double Prim(){
  vector<bool> added(building_num,false);
  vector<double> min_weight(building_num, INF);
  double min_spanning = 0;

  //시작은 정점 0부터
  min_weight[0] =0; 
  for(int iter = 0; iter<building_num ; ++iter){
    int u = -1; //다음에 트리에 추가될 정점 u

    for(int v = 0; v<building_num ; ++v)
      //현재 저장된 min_weight중에 가장 작은 정점으로
      if(!added[v] && (u == -1 || min_weight[u] > min_weight[v]))
        u = v;
    
    //스패닝 트리에 추가
    min_spanning += min_weight[u];
    added[u] = true;

    double weight;
    for(int v=0; v<building_num ; ++v){
      if(added[v])  //이미 스패닝 트리에 추가된 정점은 패스
        continue;

      weight = dist[u][v];
      //현재 min_weight보다 더 작은 경우만 갱신해줌
      if( min_weight[v] > weight)
        min_weight[v] = weight;
    }

  }
  return min_spanning;
}

int main(){
  int test_num;
  scanf("%d", &test_num);

  while(test_num--){
    scanf("%d %d", &building_num, &cable_num);
    dist = vector<vector<double>>(building_num, vector<double>(building_num,-1));

    int x, y;
    for(int i=0; i<building_num ; ++i){
      scanf("%d", &x);
      buildings_pos[i].first = x;
    }

    for(int i=0; i<building_num ; ++i){
      scanf("%d", &y);
      buildings_pos[i].second = y;
    }

    int u, v, x_cap, y_cap;
    double len;
    for(int i =0 ; i<cable_num ; ++i){
      scanf("%d %d", &u, &v);
      //이미 연결된 간선은 추가 비용에 계산되지 않는다.
      dist[u][v] = dist[v][u] = 0;
    }

    for(int i=0; i<building_num ; ++i)
      for(int j=0; j<building_num ; ++j)
        if(dist[i][j] == -1){
          x_cap = abs(buildings_pos[i].first - buildings_pos[j].first);
          y_cap = abs(buildings_pos[i].second - buildings_pos[j].second);
          len = pow(x_cap, 2) + pow(y_cap,2);
          len = sqrt(len);
          dist[i][j] = dist[i][j] = len;
        }
      
    

    printf("%.10f\n", Prim());
  }

  return 0;
}
