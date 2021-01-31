//https://www.acmicpc.net/problem/17298
#include <iostream>
#include<stack>
using namespace std;

int arr_size;
int arr[1000000];
int nge[1000000];

int main(){
  ios_base::sync_with_stdio(0);
  cin>>arr_size;

  for(int i=0; i<arr_size ; ++i)
    cin>>arr[i];
  
  stack<int> st;
  nge[arr_size-1] = -1;
  st.push(arr[arr_size -1]);
  for(int i = arr_size-2; i>=0  ; --i){
    while(!st.empty() && st.top() <= arr[i])
      st.pop();

    if(st.empty())
      nge[i] = -1;
    else
      nge[i] = st.top();
    
    st.push(arr[i]);
  }

  for(int i=0; i<arr_size ; ++i)
    cout<<nge[i]<<' ';
  
  cout<<'\n';

  return 0;
}
