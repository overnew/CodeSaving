/*
https://algospot.com/judge/problem/read/BOGGLE
완전 탐색으로는 시간초과..
아직 클리어 못함
메모이제이션 하기
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

char dr[9] = {-1,-1,-1,0,0,0,1,1,1};
char dc[9] = { -1,0,1,-1,0,1,-1,0,1 };

class Position {
	int r; int c;
public:
	Position(int _x = -1, int _y = -1) :r(_x), c(_y) {}

	int GetR() { return r; }
	int GetC() { return c; }
	bool Check(int _r, int _c) {
		if (_r == r && _c == c)
			return true;
		else
			return false;
	}
};

class Store {
	int num;
	
public:
	vector<Position> stack;

	Store(int _num=0) :num(_num) {}

	void AddPosition(int r, int c) {
		++num;
		stack.push_back(Position(r, c));
	}
	bool IsEmpty() {
		return num == 0 ? true : false;
	}
	int stack_size() {
		return stack.size();
	}
	bool isInStack(int r,int c) {
		for (int i = 0; i < stack.size() ; i++) {
			if (stack[i].Check(r, c))
				return true;
		}
		return false;
	}
};


bool isHave(const string* arr, const string& str, Store cache[] , int idx, int remain, int row, int colum) {
	int r;
	int c;
	int n = str[idx] % 65;

	if (remain == 0)
		return true;

	if (cache[n].IsEmpty())
		return false;

	if (idx == 0) {
		for (int i = 0; i < cache[n].stack_size(); i++) {

			++idx;
			--remain;
			if (isHave(arr, str, cache, idx, remain, cache[n].stack[i].GetR(), cache[n].stack[i].GetC()))
				return true;
			--idx;
			++remain;

		}
		
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (i == 4)
				continue;
			else {
				r = dr[i] + row;
				c = dc[i] + colum;
				if ((r >= 0 && r < 5) && (c >= 0 && c < 5) && cache[n].isInStack(r, c)) {
					
					++idx;
					--remain;
					if (isHave(arr, str, cache, idx, remain, r, c))
						return true;
					--idx;
					++remain;
				}
			}
		}
	}
	return false;
}

int main() {
	int case_num;
	int word_num;
	string temp;
	string arr[5];
	vector<string> words;
	Store cache[26];

	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		for (int j = 0; j < 5; j++) {  //해당 5x5칸 받아옴
			cin >> arr[j];
		}

		for (int r=0; r<5 ; ++r) {
			for (int c=0; c<5 ; c++) {
				cache[(arr[r][c] % 65)].AddPosition(r,c);
			}
		}

		cin >> word_num;
		for (int j = 0; j < word_num; j++) {
			cin >> temp;
			words.push_back(temp);
		}

		for (int j = 0; j < word_num; j++) {
			cout << words[j];

			if ( isHave(arr,words[j],cache,0,words[j].size(),0,0))
				cout << " YES" << endl;
			else
				cout << " NO" << endl;
		}

		words.clear();
	}
}


/*
bool isIt(const string* arr, const string& str) {
	string::size_type n= string::npos;

	for (int i=0; i < str.size(); i++) {
		for (int j = 0; j < 5; j++) {
			n = arr[j].find(str[i]);
		}
		if (n != string::npos)
			return true;
	}
	return false;
}

bool re_check(const string* arr,const string& str, int idx,int remain, vector<int>& route) {
	if (remain == 0)
		return true;

	if (idx == 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == str[idx]) {
					++idx;
					--remain;
					route.push_back((10*i)+j);

					if (re_check(arr, str, idx, remain, route)) //다 찾으면 종료
						return true;

					--idx;
					++remain;
					route.pop_back();
				}
			}
		}
	}
	else {
		int row = route[idx-1]/10; // 직전에 글자의 위치를 가져옴
		int colums = route[idx - 1] % 10;

		int first_r = row - 1;
		int first_c = colums - 1;
		int r, c;

		for (int i=0; i<9 ; i++) {
			if (i == 4)
					continue;
			r = first_r + (i / 3);
			c = first_c + (i % 3);
			if ((r >= 0 && r < 5) && (c >= 0 && c < 5) && (arr[r][c])== str[idx]) {
				++idx;
				--remain;
				route.push_back((10 * r) + c);

				if (re_check(arr, str, idx, remain, route)) //다 찾으면 종료
					return true;

				--idx;
				++remain;
				route.pop_back();
			}
		}
	}
	return false;
}

int main() {
	int case_num;
	int word_num;
	string temp;
	string arr[5];
	vector<string> words;
	vector<int> route;

	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		for (int j = 0; j < 5; j++){  //해당 5x5칸 받아옴
			cin >> arr[j];
		}

		cin >> word_num;

		for (int j = 0; j < word_num; j++) {
			cin >> temp;
			words.push_back(temp);
		}

		for (int j = 0; j < word_num; j++) {
			vector<int> tt;
			cout << words[j];

			if (isIt(arr,words[j]) &&re_check(arr, words[j], 0, words[j].size(), tt))
				cout << " YES" << endl;
			else
				cout << " NO" << endl;
		}
		words.clear();
		route.clear();
	}

	return 0;
}
*/
