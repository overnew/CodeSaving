#include<iostream>
using namespace std;

int borrowCost[1000];

int main(){
  int numTest;
  int maxDays,numTeam;
  double minCost;
  double divResult;
  cin>>numTest;

  for(int i=0; i <numTest ; ++i){
    cin>>maxDays>>numTeam;

    for(int j=0; j<maxDays ; ++j)
      cin>>borrowCost[j];

    minCost = 100; //모든 비용은 100이하이므로 100이 평군의 최대값

    for(int j = numTeam; j<=maxDays ; ++j){
      double sum = 0;

      for(int k=0; k<j ; ++k)
        sum += borrowCost[k]; //일단은 0~j-1까지 더해둠
      divResult = sum/j;
      minCost = minCost < divResult ? minCost: divResult;

      for(int starIdx=j; starIdx< maxDays ; ++starIdx){
        sum -= borrowCost[starIdx-j];   //가장 앞의 수를 빼주고
        sum += borrowCost[starIdx];     //그 뒤 차례의 수를 더해줌
        divResult = sum/j;
        minCost = minCost < divResult ? minCost: divResult;
      }

    }

    printf("%.11f\n",minCost);
  }

  return 0;
}
