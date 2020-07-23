https://www.acmicpc.net/problem/5639

#include <iostream>
#include<vector>
using namespace std;

typedef struct bin{
  int value;
  bin* left;
  bin* right;
}binTree;


int main() {
  int temp;
  binTree* binp;
  vector<binTree> v;
  while(true){
    cin>>temp;

    if(temp ==-1)
      break;

    if(v.empty()){
      v.push_back(binTree{temp,NULL,NULL});
    }
    else{
      binp = &v[0];

      while(1){
        if(temp < binp->value){
          if(binp->left != NULL)
            binp = binp->left;
          else{
            v.push_back(binTree{temp,NULL,NULL});
            binp->left = &v[v.size()-1];
            break;
          }

        }else{
          if(binp->right != NULL)
              binp = binp->right;
          else{
            v.push_back(binTree{temp,NULL,NULL});
            binp->right = &v[v.size()-1];
            break;
          }

          
        }


      }

    }
  }

  for(int i=0; i<v.size() ; ++i){
    cout<<v[i].value<<endl;
  }

  binp = &v[0];
  while(binp->left != NULL){
    cout<<binp->value<<endl;
    binp = binp->left;
  }

  


  return 0;
}
