//https://www.acmicpc.net/problem/6603

/*
  재귀 호출을 dfs식으로 호출해냄
  selected된 6개의 숫자를 출력
*/

#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> set;
vector<bool> selected;

void PrintLotto(){
  for(int i=0; i<k ; ++i){
    if(selected[i])
      cout<<set[i]<<' ';
  }
  cout<<'\n';
}

void lotto(int cnt,int st){
  if(cnt== 6){
    PrintLotto();
    return;
  }else{
    for(int i=st; i<k; ++i){
      if(!selected[i]){
        selected[i] = true;
        lotto(cnt+1,i+1);
        selected[i] =false;
      }
    }

  }

}

int main() {
  int temp;

  ios_base::sync_with_stdio(0);
  while(1){
    cin>>k;
    if(k==0)
      break;
    set.clear();
    for(int i=0; i<k ; ++i){
      cin>>temp;
      set.push_back(temp);
    }
    selected = vector<bool>(k,false);

    lotto(0,0);
    cout<<'\n';         //<---- 한칸씩 안 띄어서 틀림.. 
  }
  return 0;
}
