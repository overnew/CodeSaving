//https://www.acmicpc.net/problem/10164
#include <iostream>
using namespace std;

int row,col;
int selected_num;
int dp[16][16];

int main() { 
  cin>>row>>col>>selected_num;

  for(int i=0; i<row ; ++i)
    dp[i][0] =1;
  
  for(int i=0; i<col ; ++i)
    dp[0][i] =1;
  
  int result;

  if(selected_num ==0){
    for(int r=1; r<row ; ++r)
      for(int c=1; c<col ; ++c)
        dp[r][c] = dp[r-1][c] + dp[r][c-1];
      
    result = dp[row-1][col-1];
  }else{
    int cnt=0;
    int dest_row,dest_col;
    
    for(int r=0; r< row ; ++r)
      for(int c=0 ; c<col ; ++c ){
        ++cnt;
        if(cnt == selected_num){
          dest_row = r+1;
          dest_col = c+1;
          break;
        }
      }
    
    for(int r=1; r<dest_row ; ++r)
      for(int c=1; c<dest_col ; ++c)
        dp[r][c] = dp[r-1][c] + dp[r][c-1];
    
    result = dp[dest_row-1][dest_col-1];

    for(int r= dest_row-1; r<row ; ++r)
      dp[r][dest_col-1]=1;

    for(int c= dest_col-1 ; c<col ;++c)
      dp[dest_row-1][c] = 1;
    
    for(int r=dest_row; r<row ; ++r)
      for(int c=dest_col; c<col ; ++c)
        dp[r][c] = dp[r-1][c] + dp[r][c-1];

    result *= dp[row-1][col-1];
  }

  cout<<result<<'\n';
  return 0;
}
