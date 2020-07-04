//https://www.acmicpc.net/problem/11723
//비트마스크 연산을 공부할 수 있는 문제
/*
  ios::sync_with_stdio(false); //이걸 안하면 시간 초과..
  cin.tie(NULL);
  cout.tie(NULL);
  
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  int m,n;
  
  unsigned int set =0;
  unsigned int check =0;
  unsigned int full =(1<<21) -1 ; //1048575를 직접계산 안해도됨
  string func;
  cin>>m;

  ios::sync_with_stdio(false); //이걸 안하면 시간 초과..
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i=0; i<m ; ++i){
    cin>> func;

    if(func =="add"){
      cin>>n;
      set = set | (1<<n); 
    }else if(func =="remove"){
      cin>>n;
      set = set & ~(1<<n); 
    }else if(func =="check"){
      cin>>n;
      if(set & (1<<n))
        cout<<1<<"\n";
      else //0인경우
        cout<<0<<"\n";
    }else if(func =="toggle"){
      cin>>n;
      set = set ^ (1<<n); 
    }else if(func =="all"){
      set = full;
    }else if(func =="empty"){
      set =0;
    }
  }

  return 0;
}
