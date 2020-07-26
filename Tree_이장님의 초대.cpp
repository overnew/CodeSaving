//https://www.acmicpc.net/problem/9237
//분류는 트리인데 그리디로 풀어냄. 쉬웡

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
  int n;
  int max =0;
  ios_base::sync_with_stdio(0);
  cin>>n;

  for(int i=0; i<n ; ++i)
    cin>>arr[i];

  sort(arr, arr+n,greater<int>());
  
  for(int i=0; i<n ; ++i){
    max = max > arr[i] ? max: arr[i];
    --max;
  }

  int days = n+ 2 + max;
  cout<< days<<endl;

  return 0;
}
