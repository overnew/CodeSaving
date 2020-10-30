//https://www.acmicpc.net/problem/1780
#include <iostream>
#include<vector>
#include<string>
using namespace std;

int paper_size;
int paper_count[3]; // -1 => [0], 0=>[1] , 1=>[2]에 저장
vector<vector<int>> origin_paper;

int CountPaperValue(int size,int row,int col){
  if(size == 1)
    return origin_paper[row][col];
  
  bool is_all_same= true;
  int paper_value[9];
  int divided_size = size/3;
  int cnt=0;

  for(int i=0 ; i<3 ; i++)
    for(int j=0 ; j<3 ; j++)
      paper_value[cnt++] =CountPaperValue(divided_size, row + (divided_size*i), col+ (divided_size*j));
    
  for(int i=0; i<8 ; ++i)
    if(paper_value[i] != paper_value[i+1]){
      is_all_same =false;
      break;
    }
  
  if(!is_all_same){   // 9개가 같지 않는 경우 2를 반환
    for(int i=0; i<9 ; ++i)
      ++paper_count[paper_value[i]+1];
    return 2;   
  }else
    return paper_value[0];
  
}

int main() {
  int temp_num;
  cin>>paper_size;
  
  for(int i=0; i<paper_size ; ++i){
    vector<int> temp_vec;
    for(int j=0; j<paper_size ; ++j){
      cin>>temp_num;
      temp_vec.push_back(temp_num);
    }
    origin_paper.push_back(temp_vec);
  }

  int result =CountPaperValue(paper_size, 0, 0);
  if(result !=2)
    ++paper_count[result+1];
    
  for(int i=0; i<3 ; ++i)
    cout<<paper_count[i]<<'\n';

  return 0;
}
