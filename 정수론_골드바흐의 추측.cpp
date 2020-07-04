//https://www.acmicpc.net/problem/6588
//되다가 시간초과..

#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_NUM = 1000000;
bool prime[MAX_NUM+1];

int main() {
  int j;
  int temp;
  int l,r,half;
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  int sqrtn = int(sqrt(MAX_NUM));

  for(int i=2; i<=sqrtn ; ++i){
    if(prime[i])
      for(j =i*i; j<=MAX_NUM ; j+=i)
        prime[j] = false;
  }

  while(1){
    scanf("%d",&temp);
    if(temp ==0) break;

    l =3;//최소 3에서 시작
    r= temp-3;
    half = temp/2;

    while(true){
      if( (l+r == temp) && prime[l] && prime[r] ){   // l은 3에서부터, r은 n-3에서 시작해서 2씩 줄여,늘여가면서 찾아나감. 뭔가 간단한 느낌
        printf("%d = %d + %d\n",temp,l,r);
        break;  
      }
      l+=2; //어차피 짝수는 볼 필요x <-시간 두배로 빨라짐!
      r-=2;
      if(l>=half){
        printf("%s","Goldbach's conjecture is wrong.\n");
        break;
      }
    }
  }

  return 0;
}

#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_NUM = 1000000;
int prime[MAX_NUM+1];
vector<int> pri;

int main() {
  int j;
  int num;
  int temp;
  string wrong ="Goldbach's conjecture is wrong.";
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  int sqrtn = int(sqrt(MAX_NUM));

  for(int i=2; i<=sqrtn ; ++i){
    if(prime[i])
      for(j =i*i; j<=MAX_NUM ; j+=i)
        prime[j] = false;
  }

  for(int i=3; i<=MAX_NUM ; ++i){
    if(prime[i]){
      pri.push_back(i);
    }
  }

  vector<int>::iterator iter;

  while(true){
    cin>>num;
    if(num == 0) break;

     /*vector에 소수를 넣고 find하면 순서대로 넣어놨지만 처음부터 끝까지 모두 보면서 찾게됨. 이때 wrong인 것이 들어가면
     vector size*size만큼을 모두 찾게되어 너무 시간이 오래걸림.
      */
    for(int i=0; i<pri.size() ; ++i){
      if(pri[i]> (num/2) ) {
        cout<<wrong<<endl;
        break;
      } //이이상을 볼 필요는 없음
      temp = num;
      temp -= pri[i];
      iter = find(pri.begin(),pri.end(),temp);
      if(iter == pri.end())
        continue;
      else{
        printf("%d = %d + %d\n",num,pri[i],temp);
        break;
      }
    }

  }

  return 0;
}

//똑같은 문제가 9020번에도 있었다. 이건 b-a가 최소가 되게하는 

#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_NUM = 1000000;
bool prime[MAX_NUM+1];

int main() {
  int j;
  int temp;
  int t,l,r;;
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  int sqrtn = int(sqrt(MAX_NUM));

  for(int i=2; i<=sqrtn ; ++i){
    if(prime[i])
      for(j =i*i; j<=MAX_NUM ; j+=i)
        prime[j] = false;
  }

  cin>>t;

  for(int i=0;i<t ; ++i){
    cin>>temp;
    l = r= temp/2;

    while(true){
      if( (l+r == temp) && prime[l] && prime[r] ){
        printf("%d %d\n",l,r);
        break;  
      }
      --l;
      ++r;
    }
  }

  return 0;
}
