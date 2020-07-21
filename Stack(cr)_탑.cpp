//https://www.acmicpc.net/problem/2493

#include <iostream>
#include <string>
#include <stack>
#include<stdio.h>
using namespace std;

int top[500000]; //입력받고
int recep[500000];  //기억하고

int main() {
  int n, temp;
  stack<pair<int,int>> st; //pair로 first에는 탑의 길이를, second에는 그 탑의 위치를 기억하게함.
  ios_base::sync_with_stdio(0);
  cin>>n;
  
  for(int i=0; i<n ; ++i){
    cin>>top[i];
  }

  for(int i=n-1; i>=0 ; --i){

    while(!st.empty() && st.top().first <= top[i] ){ //스택의 위에가 현재탑보다 더 작으면 recep에 위치에 현재탑의 인덱스를 기록
      recep[st.top().second] = i+1;
      st.pop();
    }
    st.push(make_pair(top[i],i));// 다 순회후 push

  }

  if(!st.empty()){ //스택에 남있으면 자신보다 긴 탑이 안나온것 다 빼주자.
    while(!st.empty()){
      recep[st.top().second] =0;
      st.pop();
    }
  }

  for(int i=0; i<n ;++i ){
    printf("%d ",recep[i]);
  }


  return 0;
}
