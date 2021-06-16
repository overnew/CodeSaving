//https://algospot.com/judge/problem/read/PACKING
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int item_num, carrier_capacity;
int dp[1001][101];
int total_value =0;

struct ItemInfo{
  string name;
  int weight;
  int value;

  ItemInfo(string n, int w, int v): name(n), weight(w), value(v){}
};

vector<ItemInfo> item_list;

void Reconstruct(int capacity, int item_idx, vector<string>& answer_list){
  //끝에 도달한 경우
  if(item_idx == 0 || capacity <=0)
    return;

  if(dp[capacity][item_idx] == dp[capacity][item_idx -1])
    Reconstruct(capacity, item_idx-1, answer_list);
  else{
    answer_list.push_back(item_list[item_idx].name); 
    //전체 절박도 합에 추가해주자.
    total_value += item_list[item_idx].value;
    Reconstruct(capacity - item_list[item_idx].weight, item_idx-1 , answer_list);
  }
}

int main(){
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>item_num>>carrier_capacity;
    item_list.clear();
    memset(dp, 0, sizeof(dp));

    string name;
    int w, v;
    item_list.push_back({"ghost~", 0, 0});
    for(int i =0; i<item_num ; ++i){
      cin>>name>>w>>v;
      item_list.push_back(ItemInfo(name, w, v));
    }

    for(int weight = 1 ; weight  <=carrier_capacity ; ++weight){
      for(int idx =1; idx<= item_num ; ++idx){
        int choice_item =0, pass_item=0;

        //idx번째 물건을 선택하는 경우
        if(weight - item_list[idx].weight >=0)
          choice_item = dp[weight - item_list[idx].weight][idx-1] + item_list[idx].value;
        
        //idx번째 물건을 선택하지 않는 경우
        pass_item = dp[weight][idx -1];
        
        if(choice_item > pass_item)
          dp[weight][idx] = choice_item;
        else
          dp[weight][idx] = pass_item;    
      }
    }

    vector<string> answer_list;
    total_value =0;
    Reconstruct( carrier_capacity , item_num, answer_list);

    cout<<total_value<<" "<<answer_list.size()<<"\n";
    for(int i=0; i<answer_list.size() ; ++i)
      cout<<answer_list[i]<<"\n";
  }

  return 0;
}
