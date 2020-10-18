//https://algospot.com/judge/problem/read/CLOCKSYNC

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int pushedNum[10];  //누른 스위치의 위치에 그 횟수를 저장
int clockState[16];
vector<vector<int>> clockSwitch;
int minimum =INT32_MAX;

void pushSwitch(int switchIdx){
  for(int i=0; i<clockSwitch[switchIdx].size() ; ++i){
    if(clockState[clockSwitch[switchIdx][i]] ==12)
      clockState[clockSwitch[switchIdx][i]] =3;
    else
      clockState[clockSwitch[switchIdx][i]] +=3;
  }
  ++pushedNum[switchIdx];
}

void recoverClockState(int switchIdx){
  while(pushedNum[switchIdx] >0){
    for(int i=0; i<clockSwitch[switchIdx].size() ; ++i){
      if(clockState[clockSwitch[switchIdx][i]] ==3)
        clockState[clockSwitch[switchIdx][i]] =12;
      else
        clockState[clockSwitch[switchIdx][i]] -=3;
    }
    --pushedNum[switchIdx];
  }
}

void FindMinswitchNum(int switchIdx,int cnt){

  if(switchIdx <10)
    FindMinswitchNum(switchIdx+1, cnt);
  else
    return;

  for(int i=0 ; i<3 ; ++i){
    pushSwitch(switchIdx);
    ++cnt;

    for(int k=0; k<=16 ; ++k){
        if(k==16){
          minimum = minimum < cnt?  minimum : cnt;
          
          recoverClockState(switchIdx);
          return;               //더 이상 재귀를 돌아도 더 작은 수는 안나옴으로 재귀 종료
        } 
        if(clockState[k] != 12)
          break;                //for 문 탈출시 아직 정답이 아님
    }

    if(minimum-1 <= cnt)
      break;
    
    FindMinswitchNum(switchIdx+1,cnt);
  } 
  
  recoverClockState(switchIdx);
  return;
}

int main(){
  int testNum;
  cin>>testNum;

  clockSwitch.push_back(vector<int>({0, 1, 2}));
  clockSwitch.push_back(vector<int>{3, 7, 9, 11});
  clockSwitch.push_back(vector<int>{4, 10, 14, 15});
  clockSwitch.push_back(vector<int>{0, 4, 5, 6, 7});
  clockSwitch.push_back(vector<int>{6, 7, 8, 10, 12});
  clockSwitch.push_back(vector<int>{0, 2, 14, 15});
  clockSwitch.push_back(vector<int>{3, 14, 15});
  clockSwitch.push_back(vector<int>{4, 5, 7, 14, 15 });
  clockSwitch.push_back(vector<int>{1, 2, 3, 4, 5 });
  clockSwitch.push_back(vector<int>{ 3, 4, 5, 9, 13});

  for(int i=0; i<testNum ; ++i){
    memset(pushedNum, 0, sizeof(pushedNum));
    minimum =INT32_MAX;

    for(int j=0; j<16 ; ++j)
      cin>>clockState[j];
    
    FindMinswitchNum(0,0);
    if(minimum == INT32_MAX)
      cout<<-1<<'\n';
    else
      cout<<minimum<<'\n';
  }

  return 0;
}
