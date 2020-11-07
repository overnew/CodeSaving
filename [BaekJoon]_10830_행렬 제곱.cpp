//https://www.acmicpc.net/problem/10830
#include <iostream>
#include<vector>
using namespace std;

int matrix_size;
long long B;
vector<vector<int>> matrix_A;

vector<vector<int>> multiplyMatrix(const vector<vector<int>>& matrix_left,const vector<vector<int>>& matrix_right ){
  vector<vector<int>> result_matrix;

  vector<int> temp_row;

  for(int i=0; i<matrix_size ; ++i){
    temp_row = matrix_left[i];
    vector<int> result_row;
    for(int j=0 ; j<matrix_size ; ++j ){

      vector<int> temp_column;

      for(int k=0; k<matrix_size ; ++k)
        temp_column.push_back(matrix_right[k][j]);
      
      int result =0;
      for(int k=0; k<matrix_size ; ++k)
        result+= temp_row[k]*temp_column[k];
      
      result_row.push_back(result%1000);

    }
    result_matrix.push_back(result_row);
  }

  return result_matrix;
}

vector<vector<int>> powMatirx(long long pow_num){
  if(pow_num ==1)
    return matrix_A;

  if(pow_num %2 ==1){
    return multiplyMatrix( powMatirx(pow_num-1) , matrix_A );
  }else{
    vector<vector<int>> temp = powMatirx(pow_num/2);
    return multiplyMatrix( temp , temp);
  }
}

int main() {
  cin>>matrix_size>>B;

  int temp_num;
  for(int i=0; i<matrix_size ; ++i){
    vector<int> temp_vec;
    for(int j=0; j<matrix_size ; ++j){
      cin>>temp_num;
      temp_vec.push_back(temp_num);
    }
    matrix_A.push_back(temp_vec);
  }
  
  vector<vector<int>> result_matrix = powMatirx(B);

  for(int i=0; i<matrix_size ; ++i){
    for(int j=0; j<matrix_size ; ++j)
      cout<<result_matrix[i][j]%1000<<' ';
    cout<<'\n';
  }
  
  return 0;
}
