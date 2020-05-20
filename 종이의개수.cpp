//https://www.acmicpc.net/problem/1780

#include <iostream>
#include <vector>
using namespace std;


int main(){
  int n;
  int t;
  int minus_n=0, plus_n=0, zero_n=0;
  int x=0,y=0;
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

  cout<< minus_n<<endl;
  cout<< zero_n<<endl;
  cout<< plus_n<<endl;

  return 0;
}

int CountPaper(const vector<vector<int>> paper, int minus_n, int plus_n, int zero_n,int n, int x, int y){
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
  int area[9];
  area[0] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x,y );
  area[1] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x+div_n,y );
  area[2] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x + (div_n*2),y );
  area[3] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x,y+div_n );
  area[4] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x+div_n,y+div_n );
  area[5] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x+ (div_n*2),y+div_n );
  area[6] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x,y + (div_n*2));
  area[7] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x+div_n,y + (div_n*2));
  area[8] = CountPaper(paper, minus_n,plus_n ,zero_n, div_n, x+ (div_n*2),y + (div_n*2));
  
  int m_c,z_c,p_c,t_c, is2 =0;

  for(int i=0 ; i<n ;++i){
    if(area[i] == -1) ++m_c;
    else if(area[i] == 0) ++z_c;
    else if(area[i] == 1) ++p_c;
    else ++t_c;
  }

  if(t_c != 0) return 2;
  if(m_c !=0) ++is2;
  if(z_c!=0) ++is2;
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
  return 2; // 위에서 안걸리면 2인것
}
}
