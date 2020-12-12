//https://www.acmicpc.net/problem/2618
#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

int road_num, incident_num;
vector<pair<int,int>> incident_list;
int dp[1002][1002][2];

int MovePatrolCar(int incident_idx,int patrol1_pos, int patrol2_pos ){
  if(incident_idx >= incident_num+2)
    return 0;

  int& ret = dp[patrol1_pos][patrol2_pos][0];
  if(ret != -1)
    return ret;

  int patrol1_distence = abs(incident_list[incident_idx].first - incident_list[patrol1_pos].first) + abs(incident_list[incident_idx].second - incident_list[patrol1_pos].second) +MovePatrolCar(incident_idx+1, incident_idx ,patrol2_pos);

  int patrol2_distance = abs(incident_list[incident_idx].first - incident_list[patrol2_pos].first) + abs(incident_list[incident_idx].second - incident_list[patrol2_pos].second) + MovePatrolCar(incident_idx+1, patrol1_pos ,incident_idx);

  if(patrol1_distence< patrol2_distance){
    ret = patrol1_distence;
    dp[patrol1_pos][patrol2_pos][1] = 1;
  }else{
    ret = patrol2_distance;
    dp[patrol1_pos][patrol2_pos][1] = 2;
  }

  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin>>road_num>>incident_num;

  int r,c;
  incident_list.push_back(make_pair(1, 1));
  incident_list.push_back(make_pair(road_num, road_num));

  for(int i=0; i<incident_num ; ++i){
    cin>>r>>c;
    incident_list.push_back(make_pair(r, c));
  }

  memset(dp, -1, sizeof(dp));
  cout<<MovePatrolCar(2, 0, 1)<<'\n';

  int pos1=0,pos2=1;
  for(int i=2; i<incident_num+2 ;++i)
    if(dp[pos1][pos2][1]  ==1){
      cout<<"1\n";
      pos1 = i;
    }else{
      cout<<"2\n";
      pos2= i;
    }

  return 0;
}
