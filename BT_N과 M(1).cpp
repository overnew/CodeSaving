//https://www.acmicpc.net/problem/15649

#include <iostream>
#include<string.h>
using namespace std;

int N,M;
bool selected[9];
int arr[9];

void Recursive(int cnt){

  if(cnt == M){
    for(int i=0; i<M ; ++i){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
  }

  for(int i=1; i<=N ; ++i){
    if(!selected[i]){
      selected[i]= true;
      arr[cnt] = i;
      Recursive(cnt+1);
      selected[i] = false;
    }
  }

}

int main() {
  cin>>N>>M;
  memset(selected, false,sizeof(selected));

  Recursive(0);

  return 0;
}
