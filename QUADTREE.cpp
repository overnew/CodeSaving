[QUADTREE](https://algospot.com/judge/problem/read/QUADTREE#c16650)
/*
아래는 스택으로 카운트를 넣었더니 오버플로우가 나옴 ㅠ
스택을 사용하지 않는 재귀로으로 바꿔야함
+ 훨씬 좋은 재귀로 변형. x가 나올때마다 재귀를 호출

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string unpack(const vector<char>& com, int& idx) {
	int where = 0;
	string number[4];

	if (com.size() == 1) {
		string temp;
		temp += com[0];
		return temp;
	}


	for (int i = 0; i<4 ;++i) {
		if (com[idx] == 'x') {
			number[i] += unpack(com, ++idx);
		}
		else
			number[i] += com[idx++];
	}

	return "x" +number[2] + number[3] + number[0] + number[1];
}

int main() {
	int idx = 1;
	int case_num;
	vector<char> compact;
	string temp;
	cin >> case_num;

	for (int i=0; i <case_num ; ++i) {
		cin >> temp;
		idx = 1;

		for (int j=0; j<temp.size() ; ++j) {
			compact.push_back(temp[j]);
		}

		cout << unpack(compact, idx) << endl;

		compact.clear();
	}
	return 0;
}	   
	   
	   
/* 바꾸기 전 코드_ 스택 활용*/ 
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

void unpack(const vector<char>& com) {
	int idx = 1; // x는 없애버림
	int counter = 0;
	int where = 0;
	int com_length = com.size();
	vector<char> number[4];
	stack<int> count_stack;

	if (com_length == 1) {
		cout << com[0];
		return;
	}else
		cout<< com[0];

	while (idx < com_length) {
		++counter;
		number[where].push_back(com[idx]);


		if (com[idx] == 'x') {
			count_stack.push(counter);
			counter = 0;
		}

		if (!count_stack.empty()) {
			if (counter >= 4) {
				counter = count_stack.top();
				count_stack.pop();
			}
		}
		
		if (count_stack.empty()) 
			++where;

		++idx;
	}

	unpack(number[2]);
	unpack(number[3]);
	unpack(number[0]);
	unpack(number[1]);
	
}

int main() {
	int case_num;
	vector<char> compact;
	string temp;
	cin >> case_num;

	for (int i=0; i <case_num ; ++i) {
		cin >> temp;

		for (int j=0; j<temp.size() ; ++j) {
			compact.push_back(temp[j]);
		}

		unpack(compact);
		cout << endl;

		compact.clear();
	}
	return 0;
}
	   
	   
	  
