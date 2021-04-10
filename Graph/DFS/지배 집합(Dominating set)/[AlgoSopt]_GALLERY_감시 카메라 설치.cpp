//https://algospot.com/judge/problem/read/GALLERY
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int gallery_num, corridor_num, camera_cnt;
vector<vector<int>> adj;
bool visited[1001];
const int UNWATCHED_CHILD = 3;
const int WATCHED_BY_CHILd = 2;
const int ONLY_CHILD_WATCHED = 1;

int InstallCameraDFS(int now_gallery){
  visited[now_gallery] = true;

  int next_gallery, watched_state =0;
  for(int i=0; i<adj[now_gallery].size() ; ++i){
    next_gallery = adj[now_gallery][i];
    if(!visited[next_gallery])
      watched_state = max(watched_state, InstallCameraDFS(next_gallery));
  }

  if(watched_state == UNWATCHED_CHILD){ //감시되지 않는 자식 노드가 있는 경우 이번 갤러리에 설치
    ++camera_cnt;
    return WATCHED_BY_CHILd;
  }else if(watched_state == WATCHED_BY_CHILd){  //자식 노드가 이번 갤러리를 감시하는 경우 이번 갤러리의 부모도 설치할 필요는 없음.
    return ONLY_CHILD_WATCHED; 
  }else if(watched_state == ONLY_CHILD_WATCHED){  //자식 노드만 감시되는 경우 이번 갤러리의 부모에 설치.
    return UNWATCHED_CHILD;
  }else{  //watched_state == 0, 리프 노드는 설치하지 않아 감시되지 않음
    return UNWATCHED_CHILD;
  }

}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>gallery_num>>corridor_num;
    adj = vector<vector<int>>(gallery_num);

    int a,b;
    for(int i=0; i<corridor_num ; ++i){
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    memset(visited,false , sizeof(visited));
    camera_cnt = 0;

    for(int i=0; i<gallery_num ; ++i){
      if(!visited[i])
        if(InstallCameraDFS(i) == UNWATCHED_CHILD)
          ++camera_cnt;
    }

    cout<<camera_cnt<<'\n';
  }

  return 0;
}
