//https://www.acmicpc.net/problem/15654

#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n,m;
int answer[9];
bool selected[9];
int arr[9];

void Recur(int cnt){
  if(cnt == m){
    for(int i=0; i<m ; ++i){
      cout<<answer[i]<<' ';
    }
    cout<<'\n';
    return;
  }

  for(int i= 0; i<n ; ++i){
    if(!selected[i]){
      selected[i] = true;
      answer[cnt] = arr[i];
      Recur(cnt+1);
      selected[i] = false;
    }
    
  }

}

int main() {
  cin>> n>>m;
  for(int i=0; i<n ; ++i){
    cin>>arr[i];
  }

  sort(arr, arr+n);
  memset(selected, false, sizeof(selected));
  Recur(0);

  return 0;
}
