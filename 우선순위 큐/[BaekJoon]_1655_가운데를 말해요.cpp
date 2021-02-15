//https://www.acmicpc.net/problem/1655
#include<queue>
#include<cstdio>
using namespace std;

int main(){
  priority_queue<int, vector<int>,greater<int>> min_pq;
  priority_queue<int, vector<int>, less<int>> max_pq;
  int num_size;
  scanf("%d",&num_size);

  max_pq.push(-10001);
  min_pq.push(10001);

  int n,temp;
  for(int idx=1; idx<=num_size ; ++idx){
    scanf("%d",&n);
    if(idx %2 == 1){  //홀수 번째 수
      if(n>min_pq.top()){
        temp = min_pq.top();
        min_pq.pop();
        max_pq.push(temp);
        min_pq.push(n);
      }else{
        max_pq.push(n);
      }
    }else{  //짝수 번째 수
      if(n<max_pq.top()){
        temp = max_pq.top();
        max_pq.pop();
        min_pq.push(temp);
        max_pq.push(n);
      }else{
        min_pq.push(n);
      }
    }
    printf("%d\n",max_pq.top());
  }

  return 0;
}
