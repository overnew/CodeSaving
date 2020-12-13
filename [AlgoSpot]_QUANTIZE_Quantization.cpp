//https://algospot.com/judge/problem/read/QUANTIZE
#include <iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[100];
int quan_num,arr_size;
int cache_squ[100][1001];
int cache_range[100][100];
int cache_min[10][100];
const int max_value = 1000000100;

int Quantization(int set_num, int start){
  if(start >= arr_size)
    return 0;
  
  if(set_num >=quan_num)
    return max_value;

  int& ret = cache_min[set_num][start];
  if(ret != -1)
    return ret;

  ret = max_value;
  for(int end=start; end<arr_size ; ++end){
    if(set_num<quan_num)
    ret = min(ret, cache_range[start][end]+ Quantization(set_num+1, end+1));
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>arr_size>>quan_num;
    
    for(int i=0; i<arr_size ; ++i)
      cin>>arr[i];

    sort(arr,arr+arr_size);

    for(int idx =0; idx<arr_size ; ++idx)
      for(int num = 1; num <=1000 ; ++num)
        cache_squ[idx][num] = pow(arr[idx] - num ,2);

    int min_quan=max_value,sum=0;
    for(int end=0; end<arr_size ; ++end)
      for(int start =0; start<=end ; ++start){
        min_quan = max_value;

        for(int num =arr[start]; num<=arr[end] ; ++num){
          sum =0;
          for(int idx = start ; idx<=end ; ++idx)
            sum += cache_squ[idx][num];
          
          min_quan = min(min_quan,sum);
        }
        cache_range[start][end] = min_quan;
      }
    
    memset(cache_min, -1 , sizeof(cache_min));
    cout<<Quantization(0, 0)<<'\n';
  }

  return 0;
}
