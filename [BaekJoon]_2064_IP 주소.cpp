//https://www.acmicpc.net/problem/2064
#include <iostream>
#include<string.h>
#include<string>
using namespace std;

int computer_num;
unsigned int computer_ips[1000];

void PrintIP(unsigned int ip){
  unsigned int bit_mask = (unsigned int)((1<<8) -1) << 24;
  unsigned int temp;
  int order = 3;
  string result="";
  for(int i=0; i<4 ; ++i){
    temp = ip & bit_mask;
    for(int j =order; j>0 ; --j){
      temp = temp >>8;
    }
    result += to_string(temp);
    if(i!=3)
      result += ".";

    bit_mask = bit_mask>>8;
    order--;
  }
  cout<<result<<"\n";
}

int main() {
  cin>>computer_num;

  string temp_str,sub;
  int start_idx,temp_num;
  unsigned ip_num =0;

  for(int i=0;i<computer_num ; ++i){
    cin>>temp_str;
    temp_str += ".";

    ip_num =0;
    start_idx =0;
    for(int idx=0; idx<temp_str.size() ; ++idx){
      if(temp_str[idx] == '.'){
        sub = temp_str.substr(start_idx,idx- start_idx +1);
        ip_num = (ip_num << 8);
        temp_num = stoi(sub);
        ip_num += temp_num;
        start_idx = idx+1;
      }
    }

    computer_ips[i] = ip_num;
  }

  unsigned int network_ip,network_mask=0;
  unsigned int total_and = computer_ips[0];
  unsigned int bit;
  bool is_broken;
  
  for(int bit_order=31; bit_order>=0 ; --bit_order){
    bit = 1<<bit_order;
    is_broken = false;

    for(int idx =1; idx<computer_num ; ++idx){
      if((computer_ips[0] & bit) != (computer_ips[idx] & bit)){
        is_broken = true;
        break;
      }
    }

    if(is_broken) 
      break;
    else
      network_mask |= bit;
  }

  PrintIP( computer_ips[0] &network_mask);
  PrintIP(network_mask);

  return 0;
}
