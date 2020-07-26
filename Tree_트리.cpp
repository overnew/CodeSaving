//https://www.acmicpc.net/problem/1068

/*
  정답률은 낮았지만 쉬운 문제. tree[]에 각자의 부모노드를 저장.
  EraseNode(int parent)를 재귀호출해 parent의 값을 가지고 있는 tree[]는 -2로 변경->하위 트리들이 모두 -2를 가짐.
  n은 최대 50이므로 다음은 이중 for문으로 확인만 해주면 끝
*/

#include <iostream>
#include<string.h>
using namespace std;

int tree[50];
int n;
bool leaf[50];

void EraseNode(int parent){
  for(int i=0; i<n ; ++i){
    if(tree[i] == parent){
      tree[i] = -2;
      EraseNode(i);
    }
  }
}

int main() {
  int temp,erase;
  int cnt=0;
  cin>>n;

  memset(tree, -2, sizeof(tree));
  memset(leaf, true, sizeof(leaf));
  for(int i=0; i<n ; ++i){
    cin>>tree[i];
  }
  cin>>erase;

  tree[erase] = -2; //자기 자신은 미리 바꾸어 놓고.
  EraseNode(erase);

  for(int i=0; i<n ; ++i){
    if(tree[i] == -2){
      leaf[i] = false;
      continue;
    }
    for(int j=0; j<n ; ++j){
      if(tree[j] == i){
        leaf[i] = false;
        break;
      }
    }
  }

  for(int i=0; i<n ; ++i){
    if(leaf[i])
      ++cnt;
  }

  cout<<cnt<<'\n';

  return 0;
}
