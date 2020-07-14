//https://www.acmicpc.net/problem/2143

/*
  처음에는 투포인터로 a,b를 이중으로 겹쳤지만 틀림
  부분합을 사용하여 정렬후 lower_bound(특정 값 이상일때의 첫 포인터 반환), upper_bound(특정값보다 더 큰 값일 때의 첫 포인터 반환)
  두 값을 저장해 high - low를 해주면 만약 찾는 값이 없더라도 0이되고 찾는 값이 있으면 그만큼의 개수가 계산됨!
  -STL을 열심히 해야되는 이유가 계속 나온다..
*/


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a[1001];
long long b[1001];

int main() {
  ios_base::sync_with_stdio(0);
  long long t,n,m;
  long long temp,i,j;
  
  vector<long long> asum;
  vector<long long> bsum;

  cin>>t>>n;

  a[0] = b[0] =0;
  cin>>a[1];
  for(long long i=2; i<=n ; ++i){
    cin>>temp;
    a[i] = temp + a[i-1];
  }

  cin>>m>>b[1];
  for(long long i=2;i<=m ; ++i){
    cin>>temp;
    b[i] = temp + b[i-1];
  }

  for( i=0; i<n ; ++i){
    for(j=i+1; j<=n ; ++j){
      asum.push_back(a[j] -a[i]);
    }
  }

  for( i=0; i<m ; ++i){
    for(j=i+1; j<=m ; ++j){
      bsum.push_back(b[j] -b[i]);
    }
  }


  sort(asum.begin(), asum.end());
  sort(bsum.begin(), bsum.end());

  long long low,high,result;
  result =0;

  for(i=0 ; i< asum.size() ; ++i){
    low = lower_bound(bsum.begin(),bsum.end(), t-asum[i]) - bsum.begin();
    high = upper_bound(bsum.begin(), bsum.end(), t -asum[i]) - bsum.begin();

    result += high -low;
  }

  cout<<result<<endl;


  return 0;
}
