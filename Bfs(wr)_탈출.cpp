//https://www.acmicpc.net/problem/3055
//다시 풀어보기

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int R,C;
char forest_map[50][50];
queue<pair<int,int>> q;
int ch_r[4] = {1,0,-1,0};
int ch_c[4] = {0,1, 0 ,-1};

int EscapeBFS(){
	int days =0;
	int next_cnt=0;
	int now_cnt =2; //물과 고슴도치는 하나씩 이므로 처음에는 총 두개
	int r,c,nr,nc;
	
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		--now_cnt;
		
		if(forest_map[r][c]=='*'){
			for(int i=0; i<4 ; ++i){
				nr = r+ch_r[i];
				nc = c+ch_c[i];
				if(0<= nr && nr<R && 0<=nc && nc <C ){
					if(forest_map[nr][nc] != 'D' &&forest_map[nr][nc] != 'X' ) {//입구와 돌에는 물에 차지 않음
						if(forest_map[nr][nc] == 'S'){ //고슴도치의 위치가 잠기는 경우
							forest_map[nr][nc] = 'O'; //큐에 대기중인 경우 이를 패스하기 위해 o를 대입
						}
						forest_map[nr][nc] = '*'; //물로 채워주기
						q.push(make_pair(nr,nc));
						++next_cnt;
					}
				}
			}
		}else {
			for(int i=0; i<4 ; ++i){
				nr = r+ch_r[i];
				nc = c+ch_c[i];
				if(0<= nr && nr<R && 0<=nc && nc <C ){
					if(forest_map[nr][nc] == '.' ){// . 인곳만 이동해야함
						forest_map[nr][nc] = 'S'; //고슴도치로 채워줌
						q.push(make_pair(nr,nc));
						++next_cnt;
					}
					
				}
			}
		}
		
		if(now_cnt ==0){
			++days;
			now_cnt = next_cnt;
			next_cnt =0;
			
		}
	}
	
}

int main(){
	int water_r,water_c;
	int hedgehog_r, hedgehog_c;
	
	cin>>R>>C;
	
	for(int i=0; i<R ; ++i){
		for(int j=0; j<C ; ++j){
			cin>>forest_map[i][j];
			if(forest_map[i][j]=='S'){
				hedgehog_r = i;
				hedgehog_c =j;
			}else if(forest_map[i][j]=='*'){
				water_r = i;
				water_c = j;
			}
		}
	}
	
	q.push(make_pair(water_r, water_c)); //물부터 넣어주어야 물이 찰 예정인 칸에 고슴도치의 이동을 막을 수 있음
	q.push(make_pair(hedgehog_r,hedgehog_c)); 
	
	int result =EscapeBFS();
	if(result == -1)
		cout<<"KAKTUS"<<'\n';
	else
		cout<<result<<'\n';
	
	return 0;
}
