//https://www.acmicpc.net/problem/2661
//시간 초과가 발생


#include <iostream>
#include <string>
using namespace std;

int n;
bool clear = false;
string st;

bool CheckNice(){
  string temp;
  string find_temp;
  for(int i=2; i<=n/2 ; ++i){
    for(int j=0; j+i<=n ; ++j){
      if(j+i+i >n)
        break;

      temp = st.substr(j,i);
      find_temp = st.substr(j+i,i);

      if( find_temp.find(temp) != std::string::npos) //find함수는 해당 문자열을 못찾을 시 std::string::npos을 반환
        return false;

    }

  }
  return true;
}

void RecurNiceArr(int cnt){ 
  if(cnt == n){
    if(CheckNice()){ //dfs이기 때문에 가장 작은 값들부터 확인 ->true라면 그것이 최솟값이됨
      string answer = st.substr(0,n);
      cout<<answer<<'\n';
      clear = true;
    }
    return;
  }

  string temp;
  for(int i=1; i<=3 ; ++i){
    if(clear)
      return;
    
    if(st[cnt-1] != i+'0' || cnt==0){
      temp = (i + '0');
      st.append(temp);

      RecurNiceArr(cnt+1);
      st.erase(cnt);
    }
  }

}

int main() {
  cin>>n;

  RecurNiceArr(0);

  return 0;
}
