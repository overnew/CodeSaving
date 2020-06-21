//https://www.acmicpc.net/problem/1541
// -가 하나라도 나오면 그 다음은 다 빼버리면 됨

#include <iostream>
#include <string>
using namespace std;

int num[50];
int idx=0;
string temp;

int GetNumber(int idx){
  int sum=0;
  for(int i = idx; temp[idx] =='+' || temp[idx] =='-'  ; ++i){
    sum *= 10;
    sum += 
  }

}


int main() {
  
  int t=0;
  int n =0;
  int sum =0;
  bool minus = false;
  cin>> temp;

  for(int i=0; i<temp.length() ; ++i){
    if(temp[i]=='-'){
      if(minus) minus= true;
      n =t;
      sum -= n;
      t =0;
    }else if(temp[i] == '+'){
      n =t;

      if(minus){ //자신의 앞에 빼기가 있는지{
        sum -= n;
      }else{
        sum += n;
      }
      t=0;

    }else{
      t *= 10;
      t += temp[i] - '0';
    }
  }



  return 0;
}
