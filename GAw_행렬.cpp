//https://www.acmicpc.net/problem/1080

#include <iostream>
#include <string>
using namespace std;

int N; int M;
int A[50][50];
int B[50][50];

int main() {
  string temp;
  int count =0;
  bool same = true;
  cin>>N>>M;

  for(int i=0 ; i<N ; ++i){
    cin>> temp;
    for(int j=0; j<M ; ++j){
      A[i][j] = temp[j] - '0';
    }
  }

  for(int i=0 ; i<N ; ++i){
    cin>> temp;
    for(int j=0; j<M ; ++j){
      B[i][j] = temp[j] - '0';
    }
  }

  for(int i=0; i<N-2 ; ++i){
    for(int j=0; j<M-2 ; ++j){
      if(A[i][j] != B[i][j]){ /*3*3에서 왼쪽위의 값은 그 행렬만 바꿀수 있음. 따라서 왼쪽 위의 값이 다르다면
      연산을 진행하면됨. 또한 값은 곳의 연산을 두번 진행하는것은 전혀 의미가 없기에 위에서 하나씩 확인하며 내려가느것
      최소값이 됨*/
        ++count;
        for(int k=0; k<9 ; ++k){
          A[i+(k/3)][j+(k%3)] = !A[i+(k/3)][j+(k%3)];
        }
      }
    }
  }

  for(int i=0; i<N ; ++i){
    for(int j=0; j<M ; ++j){
      if(A[i][j] != B[i][j]){
        same= false;
        break;
      }
    }
    if(!same) break;
  }

  if(same){
    cout<<count<<endl;
  }else{
    cout<<-1<<endl;
  }


  return 0;
}
