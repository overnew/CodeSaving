//https://www.acmicpc.net/problem/15652

#include <iostream>
using namespace std;

int n,m;
int arr[8];

void Recur(int cnt, int idx){
  if(cnt == m){
    for(int i=0; i<m ; ++i){
      cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return;
  }

  for(int i=idx; i<=n ; ++i ){
    arr[cnt] = i;
    Recur(cnt+1,i); 
  }

}

int main() {
  cin>> n>>m;

  Recur(0,1); 

  return 0;
}
