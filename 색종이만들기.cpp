//https://www.acmicpc.net/problem/2630
//군대에서 처음 푸는 문제이네, 이차원vector는 일단 1차원 vector 만든다음 넣어줘야함 
//no.2630

#include <iostream>
#include <vector>
using namespace std;

int CutPaper(vector<vector<int>> paper, int& wn, int& bn,int n,int x, int y){
    if(n ==1 ){
        if(paper[x][y] == 0){
            ++wn;
            return 0;
        }else{
            ++bn;
            return 1;
        }
    }

    int div_n = n/2;
    int area[4];
    area[0] = CutPaper(paper, wn, bn, div_n, x, y);
    area[1] = CutPaper(paper, wn, bn, div_n, x+div_n, y);
    area[2] = CutPaper(paper, wn, bn, div_n, x, y+div_n);
    area[3] = CutPaper(paper, wn, bn, div_n, x+div_n, y+div_n);

    int sum = area[0] + area[1] +area[2] +area[3] ;

    if(sum == 0){
        wn -= 3;
        return 0;
    }else if(sum == 4){
        bn -= 3;
        return 1;
    }
    else{
        return 5;
    }
    
}


int main(){
    int n;
    int t;
    int wn=0;
    int bn=0;
    int x= 0, y=0;

    vector<vector<int>> paper;
    vector<int> temp;
    cin>>n;

    for(int i=0 ; i< n ; ++i){
        for(int j =0 ; j<n ; ++j){
            cin>> t;
            temp.push_back(t);
        }
        paper.push_back(temp);
        temp.clear();
    }

    CutPaper(paper, wn, bn, n, x, y);

    cout<<wn<<endl;
    cout<<bn<<endl;


    return 0;
}
