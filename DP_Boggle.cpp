//https://www.algospot.com/judge/problem/read/BOGGLE

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
int changeRow[8] ={-1,-1,-1,0,1,1,1,0};    //왼쪽 위부터 시계 방향으로
int changeCol[8] = {-1,0,1,1,1,0,-1,-1};

bool FindWordRec(int _r,int _c, int idxOfChar){
  if(idxOfChar ==lenOfNowWord)  //단어의 끝에 도달하면 성공
    return true;  

  int r,c;

  for(int i=0 ; i<8 ; ++i){
    r= _r + changeRow[i];
    c= _c + changeCol[i];
 
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
          if(board[r][c] == wordNow[0])   //첫 글자가 맞는 경우에만 호출
            if(FindWordRec(r, c, 1))      //첫 글자는 맞기 때문에 1부터 탐색
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
