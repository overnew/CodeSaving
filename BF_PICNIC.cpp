//https://www.algospot.com/judge/problem/read/PICNIC

#include<iostream>
#include<string.h>
using namespace std;

int studentNum;
int partnerNum;
int totalPairNum;
bool partnerBoard[45][45]; 
bool isPosMatch[10];

void FindPairUpNum(int idx,int matchedCoupleNum){
  if(matchedCoupleNum == studentNum/2 ){
    ++totalPairNum;
    return;
  }
  else if(idx >= studentNum)
    return;

  if(isPosMatch[idx]){
    for(int j=idx+1 ; j<studentNum ; ++j)
      if(partnerBoard[idx][j] == true && isPosMatch[j]){
        isPosMatch[idx] = false;
        isPosMatch[j] = false;
        FindPairUpNum(idx+1,matchedCoupleNum+1);
        isPosMatch[idx] = true;
        isPosMatch[j] = true;
      }
  }else
    FindPairUpNum(idx+1,matchedCoupleNum);  
}

int main(){
  int testNum;
  int fr,se;
  cin>>testNum;

  for(int i=0; i<testNum ; ++i){
    cin>>studentNum>>partnerNum;

    totalPairNum =0;
    memset(partnerBoard, false, sizeof(partnerBoard));
    memset(isPosMatch, true, sizeof(isPosMatch));

    for(int j=0; j<partnerNum; ++j){
      cin>>fr>>se;
      partnerBoard[fr][se] = true;
      partnerBoard[se][fr] = true;
    }

    FindPairUpNum(0,0);
    cout<<totalPairNum<<endl;
  }

  return 0;
}
