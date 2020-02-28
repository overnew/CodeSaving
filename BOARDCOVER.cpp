/*
https://algospot.com/judge/problem/read/BOARDCOVER
완전 탐색
끈기 있게 푼건 좋았지만 해설을 약간 참조한게 아쉽다
재귀호출만 잘 만들면 생각보다 쉬운 문제
*/

#include<iostream>
using namespace std;

int fill_case[4][2][2] = { {{0,1},{1,0}}
	,{ {0,1},{1,1}}
	,{ {1,0},{1,1}}
	,{ {1,-1},{1,0}}
};
bool board[20][20];
int checkList[20][20];


int game(int h, int w) {

	int min_r=-1;
	int min_c=-1;
	bool isBreak = false;
	int ret = 0;

	for (int i=0; i<h ; ++i) { // 채울 가장 작을점 찾기
		for (int j =0; j<w ; ++j) {
			if (board[i][j] == false)
				continue;
			else {
				min_r = i;
				min_c = j;
				isBreak = true;
				break;
			}
		}
		if (isBreak)
			break;
	}

	if (!isBreak)
		return 1;

	for (int i = 0; i < 4; ++i) { // 한칸을 채우는 방법은 최대 4가지
		int r1 = min_r + fill_case[i][0][0];
		int c1 = min_c + fill_case[i][0][1];
		int r2 = min_r + fill_case[i][1][0];
		int c2 = min_c + fill_case[i][1][1];

		if ((0 <= r1 && r1 < h) && (0 <= r2 && r2 < h) && (0 <= c1 && c1 < w) && (0 <= c2 && c2 < w) &&
			board[r1][c1] == true && board[r2][c2] == true) {
			board[min_r][min_c] = board[r1][c1] = board[r2][c2] =false;
			ret += game(h,w);

			board[min_r][min_c] = board[r1][c1] = board[r2][c2] = true;
		}
		
	}
	return ret;
}

int main() {
	int case_num;
	int h, w;
	char c;
	int solution_num = 0;
	int white_num = 0;
	cin >> case_num;

	for (int i=0; i<case_num ; ++i) {
		cin >> h >> w;

		for (int j=0; j<h;++j) {
			for (int k = 0; k < w; ++k) {
				cin >> c;
				if (c == '#')
					board[j][k] = false;
				else {
					board[j][k] = true;
					++white_num;
				}
			}
		}
		
		if(white_num %3 != 0)
			solution_num = 0;
		else
			solution_num = game(h,w);

		cout << solution_num<<endl;

		solution_num = 0;
		white_num = 0;
	}
}
