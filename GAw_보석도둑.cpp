//https://www.acmicpc.net/problem/1202
/*
처음에는 보석을 내림차순(가격이 높은 순), 가방을 올림차순으로 두고 높은 가격의 보석을 먼저 두면 될거라 생각해서 이대로 이중 for문을 했더니
O(NK)가 너무 커서 시간 초과 였다. 이중 for문을 을 우선순위 큐로 바꾸면 보석을 한번만 서칭하는 것으로 문제를 해결 할 수 있다.
이런 해결법을 기억하자.
STL의 pair를 유용하게 쓸수 있었다. 공부하자..
*/

#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool sorting(pair<int,int> a, pair<int,int> b){
  return a.second > b.second ;
}

int main() {
  int N,K;
  long long sum =0;

  pair<int,int> jell[300000];
  int bag[300000];

  cin>>N>>K;

  for(int i=0; i<N ; ++i){
    scanf("%d %d", &jell[i].first, &jell[i].second ); //first가 무게
  }

  for(int i=0; i<K ; ++i){
    scanf("%d",&bag[i]);
  }

  sort(jell, jell+N);//내림차순
  sort(bag, bag+K); //올림차순

  priority_queue<int> pq;
  for(int i=0,j=0; i<K ; ++i){
    while(j<N && bag[i] >= jell[j].first)
      pq.push(jell[j++].second); //어차피 i이상의 가방에는 모두 집어 넣을 수 있으니 되는 만큼 넣어둠. 중복 서칭이 방지됨
    
    if(!pq.empty()){
      sum+= pq.top(); //비어있지 않다면 가장 큰값을 넣어주고 반복.
      pq.pop();
    }

  }

  cout<<sum<<endl;

  return 0;
}
