#include<iostream>
#include<string>
#include<string.h>
using namespace std;

char board[5][5];
bool posAlphabet[5][5][10];
int  wordNum;
string words[10];
bool isPosWords[10];
string wordNow;
int lenOfNowWord; 

void CheckPosAlp(int _r,int _c){
  int r,c;
  for(int i=0 ; i<8 ; ++i){
    r= _r;
    c=_c;
    switch(i){
      case 0: //왼쪽 위부터 시계 방향으로
        --r;
        --c;
      break;
      case 1:
        --r;
      break;
      case 2:
        --r;
        ++c;
      break;
      case 3:
        ++c;
      break;
      case 4:
        ++r;
        ++c;
      break;
      case 5:
        ++r;
      break;
      case 6:
        ++r;
        --c;
      break;
      case 7:
        --c;
      break;
    }

    if(0<=r && r<5 && 0<=c && c<5){
      posAlphabet[_r][_c][board[r][c]-'A'] =true; //
    }
  }

}


bool FindWordRec(int _r,int _c, int idxOfChar){
  if(idxOfChar ==lenOfNowWord)
    return true;

  int r,c;

  for(int i=0 ; i<8 ; ++i){
    r= _r;
    c=_c;
    switch(i){
      case 0: //왼쪽 위부터 시계 방향으로
        --r;
        --c;
      break;
      case 1:
        --r;
      break;
      case 2:
        --r;
        ++c;
      break;
      case 3:
        ++c;
      break;
      case 4:
        ++r;
        ++c;
      break;
      case 5:
        ++r;
      break;
      case 6:
        ++r;
        --c;
      break;
      case 7:
        --c;
      break;
    }

    if(0<=r && r<5 && 0<=c && c<5){
      if(board[r][c] ==  wordNow[idxOfChar] &&posAlphabet[r][c][idxOfChar]){
        posAlphabet[r][c][idxOfChar] =FindWordRec(r, c, idxOfChar +1);
      
        if(posAlphabet[r][c][idxOfChar])
          return true;
      }
      
    }
  }

  return false;
}

int main(){
  int testNum;
  
  string temp;
  cin>> testNum;


  for(int i=0; i<testNum ; ++i){
    for(int j=0; j<5 ; ++j){
      cin>>temp;
      for(int k=0; k<5 ; ++k)
        board[j][k] = temp[k];
    }

    cin>>wordNum;
    for(int j=0; j<wordNum ; ++j){
      cin>> temp;
      words[j] = temp;
    }

    for(int j=0; j<wordNum ; ++j){
      memset(posAlphabet, true, sizeof(posAlphabet));
      wordNow = words[j];
      lenOfNowWord = wordNow.length();

      isPosWords[j] =false;

      for(int r=0; r<5 ;++r ){
        for(int c=0; c<5 ; ++c)
          if(FindWordRec(r, c, 0))
            isPosWords[j]=true;
      }

    }

    for(int j=0; j<wordNum ; ++j){
      if(isPosWords[j])
        cout<<words[j]<<' '<<"YES"<<'\n';
      else
        cout<<words[j]<<' '<<"NO"<<'\n';
    }

  }

  return 0;
}
