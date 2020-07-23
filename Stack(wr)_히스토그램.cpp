//https://www.acmicpc.net/problem/1725

//종만북에도 나와있는 문제 

#include <iostream>
#include<stack>
using namespace std;

long long h[100000];

int main() {
  int n,j;
  long long ret =0;
  stack<int> st;
  ios_base::sync_with_stdio(0);
  cin>>n;

  for(int i=0; i<n ; ++i){
    cin>>h[i];
  }
  h[n] = 0; // 오른쪽끝이 1보다 작아야 마지막 스택 처리가 가능
  
  for(int i=0; i<=n ; ++i){ //h[n]까지니 i<=n
  
    while(!st.empty() && h[st.top()] >= h[i]){ 
      j= st.top();
      st.pop();
      int width = -1;

      if(st.empty())
        width = i;
      else
        width = i - st.top() -1;
      ret = ret > h[j] * width ? ret : h[j] *width;

    }
    st.push(i);
  }

  cout<<ret <<endl;

  return 0;
}
