//https://www.acmicpc.net/problem/1107
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

int destinationChanel;
bool isPosNumber[10];
int minPushNum= 500000; 

void FindMinPush(const int chanel,int cnt){
  if(cnt >= 6)
    return;

  int tempChanel, result;
  
  for( int number=0; number<10 ; ++number){
    if(isPosNumber[number]){
      tempChanel = chanel*10;
      tempChanel += number;

      result = abs(destinationChanel - tempChanel) + cnt+1;//번호를 누른 횟수도 더해줌  
      minPushNum = minPushNum <result ? minPushNum : result;

      FindMinPush(tempChanel, cnt+1);
    }
  }

}

int main(){
  int brokenNum;
  int temp;
  cin>>destinationChanel;

  memset(isPosNumber, true, sizeof(isPosNumber));

  cin>>brokenNum;
  for(int i=0 ; i<brokenNum ; ++i){
    cin>>temp;
    isPosNumber[temp] = false;
  }

  int startNowChanel = abs( destinationChanel-100);
  minPushNum = minPushNum <startNowChanel ? minPushNum: startNowChanel;   //기존 채널인 100에서 + - 누르는 것이 더 가까운지 확인

  if(brokenNum !=10)
    FindMinPush(0, 0);

  cout<<minPushNum<<endl;

  return 0;
}
