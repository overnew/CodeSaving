
#include<iostream>
#include<vector>
using namespace std;

int M=0;
vector<pair<int,int>> v[10001];

int MaxDia(int idx){
  if(v[idx].empty())
    return 0;
  
  int sum=0,cnt=0;
  int l_m =0, r_m=0;

  l_m+=v[idx][0].second;
  l_m+=MaxDia(v[idx][0].first);
  if(v[idx].size() ==2){
    r_m+=v[idx][1].second;
    r_m+=MaxDia(v[idx][1].first);
  }

  sum = l_m + r_m;
  cout<<idx<<": "<<sum<<endl;
  M = M >sum ? M: sum;
  return l_m> r_m ? l_m: r_m;
}

int main(){
  int n,idx,child,weight;
  ios_base::sync_with_stdio(0);

  cin>>n;
  for(int i=0;i<n-1 ; ++i){
    cin>>idx>>child>>weight;
    v[idx].push_back(make_pair(child,weight));
  }
  
  MaxDia(1);
  cout<<M<<endl;

  return 0;
}
