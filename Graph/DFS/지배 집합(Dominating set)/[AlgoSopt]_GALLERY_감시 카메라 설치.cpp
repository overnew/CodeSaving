//https://algospot.com/judge/problem/read/GALLERY
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int gallery_num, corridor_num;
vector<vector<int>> adj;
bool visited[1001];
int camera_cnt;

int InstallCameraDFS(int now_gallery, bool is_root){
  visited[now_gallery] = true;

  int next_gallery, camera_pos =0;
  for(int i=0; i<adj[now_gallery].size() ; ++i){
    next_gallery = adj[now_gallery][i];
    if(!visited[next_gallery])
      camera_pos = max(camera_pos, InstallCameraDFS(next_gallery, false));
  }

  if(is_root){
    if(camera_pos != 2)
      ++camera_cnt;
    return 0;
  }

  if(camera_pos == 3){ //감시되지 않는 자식 노드가 있는 경우 나에 설치
    ++camera_cnt;
    return 2;
  }else if(camera_pos == 2){  //자식 노드가 나를 감시하는 경우 나의 부모도 설치할 필요는 없음
    return 1; 
  }else if(camera_pos == 1){  //자식 노드만 감시되는 경우 나의 부모가 날 감시하게 함
    return 3;
  }else{  //camera_pos == 0, 리프 노드는 설치하지 않아 감시되지 않음
    return 3;
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
        InstallCameraDFS(i, true);
    }

    cout<<camera_cnt<<'\n';
  }

  return 0;
}
