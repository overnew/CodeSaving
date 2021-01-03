//https://www.acmicpc.net/problem/11501
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int stock_value[1000000];
  int test_num,day_num;
  cin>>test_num;

  long long stock_sum=0;
  int max_stock=0;

  for(int i =0; i<test_num ; ++i){
    cin>>day_num;
    for(int day=0; day< day_num; ++day)
      cin>>stock_value[day];
    
    stock_sum=0;
    max_stock=0;
    for(int day=day_num -1 ; day>=0 ; --day){
      if(stock_value[day] < max_stock)
        stock_sum += (max_stock - stock_value[day]);
      else
        max_stock = stock_value[day];
    }
    cout<<stock_sum<<'\n';
  }

  return 0;
}
