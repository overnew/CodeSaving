//https://www.acmicpc.net/problem/2491
#include <iostream>
using namespace std;

int arr_length;
int arr[100000];
int cache[100000][2];

int main() { 
  cin>>arr_length;

  for(int i=0; i<arr_length ; ++i)
    cin>>arr[i];
 
  cache[arr_length-1][0] = 1;
  cache[arr_length-1][1] = 1;

  int max_length=1; //최솟값은 1
  for(int idx = arr_length-2; idx>=0 ; --idx){
    if(arr[idx] < arr[idx+1]){ //커지는 경우
      cache[idx][0] = cache[idx+1][0] +1;
      cache[idx][1] = 1;
    }else if(arr[idx]> arr[idx+1]){
      cache[idx][1] = cache[idx+1][1] +1;
      cache[idx][0] = 1;
    }else{
      cache[idx][0] = cache[idx+1][0] +1;
      cache[idx][1] = cache[idx+1][1] +1;
    }

    if(cache[idx][0] > max_length)
      max_length = cache[idx][0];
    if(cache[idx][1] > max_length)
      max_length = cache[idx][1];
  }

  cout<<max_length<<'\n';
  return 0;
}
