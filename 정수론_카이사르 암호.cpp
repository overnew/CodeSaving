//https://www.acmicpc.net/problem/5598
//이런걸 왜 틀리지 했는데 카이라스 암호를 해독하는 문제를 반대로 풀고 나서 왜안되지 이러고 있다...

#include <iostream>
#include <string>
using namespace std;

int main() {
  string bef;
  char temp;

  cin>>bef;

  for(int i=0; i<bef.length() ; ++i){
    temp = bef[i];
    temp -= 3;
    if(temp<'A') temp += 26;
    cout<<temp;
  }
  cout<<endl;

  return 0;
}
