//https://www.acmicpc.net/problem/7562

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int I;
int start_r,start_c;
int goal_r, goal_c;
int board[300][300];
int ch_r[8] ={2,1,-1,-2,-2,-1,1,2};
int ch_c[8] ={1,2,2,1,-1,-2,-2,-1};

int KnightBFS(){
	board[start_r][start_c] =0;
	if(start_r == goal_r && start_c == goal_c)
		return 0;
	
	queue<pair<int,int>> q;
	q.push(make_pair(start_r, start_c));
	int r,c,nr,nc;
	
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for(int i=0; i<8 ; ++i){
			nr = r+ ch_r[i];
			nc = c+ ch_c[i];
			
			if(0<=nr &&nr<I && 0<=nc && nc<I){
				if(board[nr][nc] == -1){
					board[nr][nc] = board[r][c] +1;
					if(nr== goal_r && nc == goal_c )
						return board[nr][nc];
					q.push(make_pair(nr,nc));
				}
			}

		}
    
	}
	return -1;
}

int main(){
	int T;
	int r,c;
	cin>>T;

	for(int i=0; i<T ; ++i){
		cin>>I;
		cin>> start_r>>start_c;
		cin>>goal_r>> goal_c;
		memset(board, -1, sizeof(board));
		cout<<KnightBFS()<<'\n';
	}
	
	return 0;
}
