//https://www.acmicpc.net/problem/1038

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
int countDescendNum=9;
vector<long long> descendNumberSet;

void FindDescendNumber(int cnt){
  
  vector<long long>::iterator iter;
  vector<long long> temp;
  long long powNum = pow(10,cnt-1);

  for(int i=1; i<10 ; ++i)
  for(iter = descendNumberSet.begin(); iter<descendNumberSet.end() ;++iter ){
    if(*iter%10 < i){
      temp.push_back(powNum*i + *iter);
      ++countDescendNum;

      if(countDescendNum == N){
        cout<< powNum*i + *iter<<'\n';
        return;
      }
    }
  }

  descendNumberSet = temp;
  temp.clear();

  if(cnt<=10)
    FindDescendNumber(cnt+1);
  else
    cout<<-1<<'\n';
}

int main(){
  cin>>N;

  vector<long long> nextDescNumSet ={0,1,2,3,4,5,6,7,8,9};
  descendNumberSet = nextDescNumSet;

  if(N<10)
    cout<<N<<'\n';
  else
    FindDescendNumber(2);

  return 0;
}
