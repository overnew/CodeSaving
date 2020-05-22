//쉬운 부트포스트

#include <iostream>
#include <algorithm>

using namespace std;
int height[9];
int not_include[2];

void printOutput(){
  for(int i=0; i< 9; ++i){
    if(i != not_include[0] && i != not_include[1])
      cout<<height[i]<<endl;
  }
}

void Find100(){
  int sum =0;

  for(int i=0; i<7 ; ++i){
    sum += height[i];
  }
  not_include[0] = 7;
  not_include[1] = 8;

  if(sum == 100) {
    printOutput();
    return;
  }

  for(int i=8 ; i>0 ; --i ){
    sum += height[not_include[1]];
    sum -= height[i];
    not_include[1] = i;

    for(int j=(i-1); j>=0 ; --j){
      sum += height[not_include[0]];
      sum -= height[j];
      not_include[0] = j;
      
      if(sum == 100){
        printOutput();
        return;
      }

    }
  }

}

int main() {
  for(int i=0; i<9 ; ++i){
    cin>> height[i];
  }

  sort(height, height+ 9);

  Find100();

  return 0;
}
