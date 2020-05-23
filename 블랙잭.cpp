// 쉬운 부스트포스트
// https://www.acmicpc.net/problem/2798

#include <iostream>
#include <algorithm>
using namespace std;

int N; //카드개수
int M;
int number[100];

int BlackJack(){
  int sum=0;
  int answer=0;
  int answer_temp=0;

  for(int i=0; i<(N-2) ;++i){
    sum += number[i];

    for(int j= i+1 ; j<(N-1)  ;++j){
      sum += number[j];

      for(int k=j+1; k<N ; ++k){
        sum+= number[k];

        answer_temp = sum;
        if( M>=answer_temp && (M - answer > M-answer_temp) ){
          answer = answer_temp;
        } // >=에서 =를 안붙여서 해맴..
        
        sum -= number[k];
      }
      sum -= number[j];
    }
    sum =0;
  }


  return answer;
}


int main() {
  int temp;
  cin>>N;
  cin>>M;

  for(int i=0; i<N ; ++i){
    cin>>number[i];
  }

  sort(number, number+N);

  cout<< BlackJack()<<endl;

  return 0;
}
