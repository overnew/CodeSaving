//https://algospot.com/judge/problem/read/QUADTREE
#include <iostream>
#include<string>
using namespace std;

string Decompress(string ori){
  if(ori[0] != 'x'){
    return ori;
  }

  int subStrOrder=0;
  int count=1;
  int preSubEnd=0;
  string sub[4];

  for(int i=1; i<ori.length() ; ++i){
    if(ori[i] == 'x'){
      count+=3;
      continue;
    }
    else
      --count;
      
    if(count ==0){
      sub[subStrOrder++] = ori.substr(preSubEnd+1, i-preSubEnd);
      preSubEnd = i;
      count =1;
      continue;
    }
  }

  string UpToDownStr = "x"+ Decompress(sub[2]) +Decompress(sub[3])+Decompress(sub[0])+Decompress(sub[1]);

  return UpToDownStr;
}

int main() {
  int testNum;
  string originCompression;
  cin>>testNum;

  for(int i=0; i<testNum ; ++i){
    cin>>originCompression;

    cout<<Decompress(originCompression)<<'\n';
  }

  return 0;
}
