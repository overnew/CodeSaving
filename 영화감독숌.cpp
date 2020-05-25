//https://www.acmicpc.net/problem/1436
//뭔가 특이한 패턴이 있다고 생각했는데 아니였다..
//그냥 무식하게 풀기

#include <iostream>
using namespace std;

int N;

int Syon(){
  int order=0;
  int count=0;
  int temp=0;
  bool cont = false; //6이 이어지는지 확인

  for(int i=666; ; ++i){
    count =0;
    temp = i;
    while(temp != 0){
      if(temp%10 == 6){
        ++count;
        cont = true;
        if(count >=3 && cont){
        ++order;
        break;
        }

      }else{
        count=0;
        cont =false;
      }
      temp /= 10;
    }

    if(order == N)
      return i;
  }
}

int main() {
  cin >> N;

  cout<<Syon()<<endl;
  return 0;
}
