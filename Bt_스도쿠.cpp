//https://www.acmicpc.net/problem/2580

#include <iostream>
#include <string.h>
using namespace std;

int board[9][9];
bool printed = false; //전체 재귀의 종료 여부

void PrintBoard(){
	for(int i=0; i<9 ; ++i){
		for(int j=0; j<9 ; ++j){
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}		
	return;
}

void SdocuCheck(int r,int c){
	int nr,nc;
	bool check_next = false; //다음으로 나오는 0을 확인
	bool last =false;			//마지막 0임을 확인
	
	for(int i=r; i<9 ; ++i){
		for(int j=0; j<9 ; ++j){
			if(i==r && j==c)
				continue;
			if(board[i][j] ==0){
				nr = i;
				nc = j;
				check_next = true; //0확인시 for문 탈출
				break;
			}
		}
		if(check_next)
			break;
		
		if(i==8){ //0이 더이상 없는 경우 해결한 것
			last =true;
			break;
		}
	}
	
	bool pos_num[10];
	memset(pos_num, true , sizeof(pos_num));
	
	for(int i=0; i<9 ; ++i)
		pos_num[board[r][i]] = false; //같은 행에 나온 수는 false 로
	
	for(int i=0; i<9 ; ++i)
		pos_num[board[i][c]] = false;//같은 열에 나온 수는 false 로
	
	int start_r, start_c, end_r,end_c;
	start_r = 3*(r/3);
	start_c = 3*(c/3);
	end_r = start_r +3;
	end_c = start_c +3;
	
	for(int i= start_r; i<end_r ; ++i){
		for(int j=start_c; j<end_c ; ++j){
			pos_num[board[i][j]] = false; //같은 정사각 칸에 나오는 수 false
		}
	}
	
	for(int i=1; i<10 ; ++i){
		if(printed)
			return;
		
		if(pos_num[i]){
			if(last){	
				board[r][c] = i;
				PrintBoard();	//마지막칸 이므로 스도쿠 답을 출력 후
				printed = true;	// 전체 재귀를 종료시킴
				return;
			}
				
			board[r][c] = i;
			SdocuCheck(nr,nc);	
		}
	}
	board[r][c] = 0;//다시 돌려줌
	
}

int main(){
	int fr,fc;
	bool check_first =false;
	for(int i=0; i<9 ; ++i)
		for(int j=0; j<9 ; ++j)
			cin>>board[i][j];
	
	for(int i=0; i<9 ; ++i){
		for(int j=0; j<9 ; ++j){
			if(board[i][j]==0){
				fr=i;
				fc=j;
				check_first =true;
				break;
			}
		}
		if(check_first)
			break;
		
	}
	
	SdocuCheck(fr,fc); //처음으로 나오는 0을 확인해 함수 호출
	
	return 0;
}
