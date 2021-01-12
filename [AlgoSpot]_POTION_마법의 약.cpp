//https://algospot.com/judge/problem/read/POTION
#include <iostream>
#include<vector>
using namespace std;

int material_num;
int recipe[200];
int already_put[200];

int RecipeGcd(){
  int a,b;

  if(material_num ==1)
    return recipe[0];

  a = recipe[0];
  for(int i=1; i<material_num ; ++i){
    b = recipe[i];
    while(b!=0){
      a %= b;
      swap(a,b);
    }
  }
  
  return a;
}

int ceil(int a, int b){
  return (a+ b -1)/b;
}

int main() {
  ios_base::sync_with_stdio(0);
  int test_num,temp,gcd;
  cin>>test_num;

  while(test_num--){
    cin>>material_num;
    for(int i=0; i<material_num ; ++i)
      cin>>recipe[i];
    
    for(int i=0; i<material_num ; ++i)
      cin>>already_put[i];

    gcd = RecipeGcd();

    int k = gcd;
    for(int i=0; i<material_num ; ++i)
      k = max(k, ceil(already_put[i]*gcd, recipe[i]));
    
    for(int i=0; i<material_num ; ++i)
      cout<< (recipe[i]*k)/gcd - already_put[i]<<' ';
    
    cout<<'\n';
  }

  return 0;
}
