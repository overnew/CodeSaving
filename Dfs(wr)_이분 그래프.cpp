//https://www.acmicpc.net/problem/1707

/*
  color가 0이면 아직 방문하지 않은 노드라 가정하고. color가 0인 경우만 방문하는 dfs구조이다.
  이때 방문한 노드의 color는 호출한 상위 노드와 반대를 가져야 하므로 3-color를 매개인자로 넘겨준다.
  따라서 상위노드가 1이면 호출된 노드는 모두 2가 되는 식이다. 모든 방문을 마치고 색을 입혔다면 for문으로 순회하면 자신의 자식노드가
  자신과 같은 색일 경우 NO를 출력하면 된다.
  
  처음에는 setA와 setB를 마련하고 각각이 Ban하는 수를 이진트리로 저장하려 했지만, 1-3-2-4 로 연결된 경우.
  1과 2는 서로를 ban하지 않으므로 같은setA에 삽입될 경우 YES가 답임에도 불구하고 NO를 출력하게 된다.
  
  DFS문제는 DFS로 먼저 접근해 봐야지 맘대루 날아가 버리지 말자.
*/

#include <iostream>
#include<vector>
#include<set>
#include<string.h>
using namespace std;

int v;
int e;
const int MAX = 20001;
vector<int> graph[MAX];
int node_color[MAX];

void Dfs(int idx,int color){
  
  node_color[idx] = color;

  for(int i=0; i<graph[idx].size() ; ++i){
     int temp= graph[idx][i];
    if(node_color[temp] ==0 )
      Dfs(temp,3-color);
  }
}

bool Bipartite(){
 
  for(int i=1; i<=v ; ++i){
    for(int j=0; j<graph[i].size() ; ++j){
       int temp= graph[i][j];
       if(node_color[i] == node_color[temp])
        return false;
    }

  }
  return true;
}

int main() {
  int k,a,b;

  ios_base::sync_with_stdio(0);
  cin>>k;

  for(int i=0; i<k ; ++i){
    cin>>v>>e;

    for(int j=0; j<MAX; ++j){
      graph[j].clear();
    }

    memset(node_color, 0, sizeof(node_color));

    for(int j=0; j<e ; ++j){
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    for(int j=1; j<=v ; ++j){
      if(node_color[j]==0)
        Dfs(j, 1);
    }

    if(!Bipartite())
      cout<<"NO"<<'\n';
    else 
      cout<<"YES"<<'\n';
  }

  return 0;
}
