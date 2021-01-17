https://algospot.com/judge/problem/read/GRADUATION
#include <iostream>
#include<string.h>
using namespace std;

int class_num,semester_num, max_take_num, requir_class_num;
int prerequisite[12];
int semester_classes[10];
int cache[10][1<<12];
const int INF = 987654321;

bool CheckPrereq(const int& class_idx,const int& taken_class){
  bool is_pos = true;
  for(int i=0; i<class_num ; ++i)
    if(prerequisite[class_idx] & (1<<i))
      if(!(taken_class & (1<<i))){
        is_pos = false;
        break;
      }

  return is_pos;
}

int BitCount(const int& take){
  int cnt =0;
  for(int i=0; i<class_num ; ++i)
    if(take & (1<<i))
      ++cnt;
  return cnt;
}

int TakeClass(int semester, int taken_class){
  if(BitCount(taken_class) >=requir_class_num)
    return 0;

  if(semester >= semester_num)
    return INF;

  int& ret = cache[semester][taken_class];
  if(ret != -1)
    return ret;

  ret = INF;
  int can_take = (semester_classes[semester] & ~taken_class);

  for(int i=0; i<class_num ; ++i){
    if(can_take & (1<<i))
      if((taken_class & prerequisite[i]) != prerequisite[i])
        can_take &= ~(1<<i);
  }

  for(int take =can_take; take>0 ; take =((take-1) & can_take)){
    if(BitCount(take) <= max_take_num)
      ret = min(ret, TakeClass(semester+1, taken_class | take ) +1);
  }
  
  ret = min(ret, TakeClass(semester+1, taken_class));
  return ret;
}

int main() {
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>class_num>>requir_class_num>>semester_num>>max_take_num;

    int prereq_num,temp;
    for(int i=0; i<class_num ; ++i){
      cin>>prereq_num;
      prerequisite[i] = 0;
      for(int j=0; j<prereq_num ; ++j){
        cin>>temp;
        prerequisite[i] |= (1<<temp);
      }      
    }

    int open_class_num;
    for(int i=0; i<semester_num ; ++i){
      cin>>open_class_num;
      semester_classes[i] =0;
      for(int j=0 ; j<open_class_num ; ++j){
        cin>>temp;
        semester_classes[i] |= (1<<temp);
      }
    }
    memset(cache, -1, sizeof(cache));

    int result = TakeClass(0, 0);
    if(result == 987654321)
      cout<<"IMPOSSIBLE\n";
    else
      cout<<result<<"\n";

  }
  return 0;
}
