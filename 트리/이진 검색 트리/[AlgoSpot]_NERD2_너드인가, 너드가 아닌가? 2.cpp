//https://algospot.com/judge/problem/read/NERD2
#include <iostream>
#include<map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int test_num,p,q,sum;
  int participant_num;
  map<int,int> part_list;
  map<int,int>::iterator it_low, it_up;

  cin>>test_num;

  while(test_num--){
    sum = 0;
    cin>>participant_num;

    cin>>p>>q;
    part_list[p] = q;
    sum += 1;

    for(int i=1; i<participant_num ; ++i){
      cin>>p>>q;
      
      it_low = part_list.lower_bound(p);
      
      if(it_low == part_list.end()){
        part_list[p] = q;
      }else{
        if(it_low->second >q){
          sum += part_list.size();
          continue;
        }
        part_list[p] = q;
      }

      it_low = part_list.lower_bound(p);
      map<int,int>::iterator it_temp, it;
      
      if(it_low != part_list.begin()){
         //앞에서부터 보면 안됨. 뒤에서 부터 봐야 O(N)의 복잡도
        --it_low;

        it = it_low;
        while(1){
          it_temp = it;
          --it_temp;  //미리 --연산을 해주어야함. it이 erase된 후에는 잘못된 값이 나옴
          if(it->second < q){
            if(it == part_list.begin()){
              part_list.erase(it);
              break;
            }

            part_list.erase(it);
          }else{
            break;
          }
        
          it = it_temp;
        }

      }
      sum += part_list.size();
    }

    cout<<sum<<'\n';
    part_list.clear();
  }
  return 0;
}
