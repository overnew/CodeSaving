//https://algospot.com/judge/problem/read/FORTRESS
#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

class CastleNode{
  public:
  int x,y,r;
  vector<CastleNode*> children;

  CastleNode(int _x, int _y, int _r): x(_x), y(_y), r(_r){}
  
  void AddChild(CastleNode* b){
    CastleNode* a;

    for(int i=0; i<children.size() ; ++i){
      a = children[i];
      if(pow(a->r,2) > pow((a->x - b->x),2) + pow((a->y - b->y),2) + pow(b->r,2) ){
        children[i]->AddChild(b);
        return;
      }
      
    }
    children.push_back(b);
  }

  bool operator<(const CastleNode& cas) const{
    return (this->r) > (cas.r); 
  }

};

int castle_num,longest;
vector<CastleNode> castles;

int TreeHeigth(CastleNode* cas){
  vector<int> heights;
  int max_height=0;

  if(cas->children.size() ==0)
    return 0;
  
  for(int i=0; i<cas->children.size() ; ++i){
    heights.push_back( TreeHeigth(cas->children[i]) + 1);
    max_height= max(max_height, heights.back());
  }
  
  if(cas->children.size()>1){
    sort(heights.begin(), heights.end());
    longest = max(longest, heights[heights.size() -1] + heights[heights.size() -2]);
  }
   
  return max_height;
}

int main(){
  int test_num;
  cin>>test_num;

  int x,y,r;
  CastleNode* root;
  while(test_num--){
    cin>>castle_num;

    for(int i=0; i<castle_num ; ++i){
      cin>>x>>y>>r;
      castles.push_back(CastleNode(x,y,r));
    } 
    
    sort(castles.begin(), castles.end());

    root = &castles[0];
    for(int i=1; i<castle_num ; ++i)
      root->AddChild(&castles[i]);

    longest =0;
    int root_height = TreeHeigth(root);
    cout<<max(root_height, longest)<<"\n";

    castles.clear();
  }

  return 0;
}
