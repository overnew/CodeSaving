//https://algospot.com/judge/problem/read/SORTGAME
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

map<vector<int>, int> precal;

void SortGame(int arr_size){
  vector<int> arr(arr_size);

  for(int i=0; i<arr_size ; ++i)
    arr[i] = i+1;
  
  precal[arr] = 0;
  queue<vector<int>> que;
  que.push(arr);

  int cnt=0;
  while(!que.empty()){
    vector<int> temp = que.front();
    que.pop();

    int cost = precal[temp];
    for(int i =0 ; i<arr_size ; ++i){
      for(int j=i+2; j<=arr_size ; ++j){
        reverse(temp.begin()+i, temp.begin()+j);

        if(precal.count(temp) == 0){
          precal[temp] = cost +1;
          que.push(temp);
        }
        reverse(temp.begin()+i, temp.begin()+j);
      }
    }

  }
}

vector<int> CompressArr(vector<pair<int,int>>& arr){
  sort(arr.begin(), arr.end());

  vector<int> ret(arr.size());
  for(int i=0; i<arr.size() ; ++i)
    ret[arr[i].second] = i+1;

  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);

  for(int i=1; i<=8 ; ++i)
    SortGame(i);

  int test_num;
  cin>>test_num;

  while(test_num--){
    int arr_size;
    cin>>arr_size;
    vector<pair<int,int>> origin_arr = vector<pair<int,int>>(arr_size);

    int value;
    for(int i=0; i<arr_size ; ++i){
      cin>>value;
      origin_arr[i] = make_pair(value, i);
    }

    vector<int> compressed_arr = CompressArr(origin_arr);
    cout<<precal[compressed_arr]<<'\n';
  }

  return 0;
}
