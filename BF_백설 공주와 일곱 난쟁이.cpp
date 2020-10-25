//https://www.acmicpc.net/problem/3040
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int dwarf[9];
bool isSelected[9];

void SelectDwarf( int start,int sum,int cnt){
  if(cnt>= 7)
    if(sum == 100){
      for(int i=0; i<9 ; ++i)
        if(isSelected[i])
          cout<<dwarf[i]<<'\n';
      return;
    }

  for(int i = start; i<cnt+3 ; ++i){
    isSelected[i] = true;
    if(sum+dwarf[i]<=100 && cnt<7)
      SelectDwarf(i+1,sum+dwarf[i],cnt+1);
    isSelected[i] = false;
  }
  return;
}


int main(){
  for(int i=0; i<9 ; ++i)
    cin>>dwarf[i];

  SelectDwarf(0,0,0);

  return 0;
}
