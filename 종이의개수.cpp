//https://www.acmicpc.net/problem/1780
// 맞는 풀이 같은데 시간초과.. 전역변수를 쓰거나 덧셈 뺄셈을 좀 

#include <iostream>
#include <vector>
using namespace std;

int minus_n =0,plus_n =0, zero_n=0 ;


int CountPaper(const vector<vector<int>> paper, int n, int x, int y){

  if(n == 1){
    if(paper[x][y] == -1){
      ++minus_n;
      return -1;
    }else if(paper[x][y] == 0){
      ++zero_n;
      return 0;
    }else{
      ++plus_n;
      return 1;
    }
  }

  int div_n = n/3;
  int div2 = div_n *2;

  int area[9];
  area[0] = CountPaper(paper,  div_n, x,y );
  area[1] = CountPaper(paper,  div_n, x+div_n,y );
  area[2] = CountPaper(paper,  div_n, x + div2,y );
  area[3] = CountPaper(paper,  div_n, x,y+div_n );
  area[4] = CountPaper(paper,  div_n, x +div_n, y+div_n );
  area[5] = CountPaper(paper,  div_n, x + div2, y+div_n );
  area[6] = CountPaper(paper,  div_n, x, y + div2);
  area[7] = CountPaper(paper,  div_n, x+div_n, y + div2);
  area[8] = CountPaper(paper,  div_n, x+ div2, y + div2);
  
  int m_c=0,z_c =0,p_c=0,t_c=0, is2 =0;

  for(int i=0 ; i<9 ;++i){
    if(area[i] == -1) ++m_c;
    else if(area[i] == 0) ++z_c;
    else if(area[i] == 1) ++p_c;
    else ++t_c;
  }

  if(t_c != 0) return 2; // 2가 반환된것 이 있다면 바로 다시 2반환

  if(m_c != 0) ++is2;
  if(z_c!= 0) ++is2;
  if(p_c!=0) ++is2;

  if(is2==1){
    if(m_c !=0){
      minus_n -= 8;
      return -1;
    }else if(z_c != 0){
      zero_n -= 8;
      return 0;
    }else{
      plus_n -= 8;
      return 1;
    }
   // 위에서 안걸리면 2인것
  }
  return 2;
}

int main(){
  int n;
  int t;
  vector<vector<int>> paper;
  vector<int> temp;
  cin>>n;

  for(int i=0; i<n ; ++i){
    for(int j=0; j<n ; ++j ){
      cin>>t;
      temp.push_back(t);
    }
    paper.push_back(temp);
    temp.clear();
  }

  CountPaper(paper, n, 0,0 );

  cout<< minus_n<<endl;
  cout<< zero_n<<endl;
  cout<< plus_n<<endl;

  return 0;
}
