//https://www.acmicpc.net/problem/1966


#include <iostream>
#include <queue>
using namespace std;

int main() {
  int t,n,m,temp;
  bool is_find = false;
  queue<int> q;
  ios_base::sync_with_stdio(0);

  cin>>t;

  for(int i=0; i<t ; ++i){
    cin>>n>>m;

    for(int j=0; j<n ; ++j){
      cin>>temp;
      q.push(temp);
    }
  
    int cnt =0;
    int size =q.size();
    is_find = false;

    for(int j=9; !is_find && j>0 ; --j){
      
      for(int k=0; k<size ; ++k){
        if(q.front() == j){
        
        cnt++;
        //cout<<cnt<<": " <<q.front()<<endl;
        q.pop();
        --size;
        if(m==0){
          cout<<cnt<<endl;
          is_find = true;
          break;
        }else{
          --m;
        }

      }else{

        temp = q.front();
        q.pop();
        q.push(temp);

        if(m==0){
          m=(q.size() -1);
        }else{
          --m;
        }

      }

      }
      

    }
  }



  return 0;
}

//
#include <iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
  int test,n,m,temp;
  int num;
  priority_queue<int> pq;
  cin>>test;

  for(int i=0; i<test ; ++i){
    cin>> n>>m;

    for(int i=0; i<n ; ++i){
      cin>>temp;
      pq.push(temp);
    }

    for(int i=0; i<n ; ++i){
      if(pq.top() == m) //이렇게 하면 
    }
  }


  return 0;
}
