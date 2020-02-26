/*
https://algospot.com/judge/problem/read/PICNIC
원트 기분 좋아~
완전 탐색으로 해결
*/

#include<iostream>
#include<vector>
using namespace std;

class HaveFriends {
	int stu_num;
	int number_of_friend;
public:
	vector<bool> friendID;

	HaveFriends(int stu, int num=0):stu_num(stu),number_of_friend(num) {
		for (int i = 0; i < stu_num; ++i)
			friendID.push_back(false);
	}
	
	void AddFriend(int id) {
		friendID[id] = true;
		++number_of_friend;
	}

	bool isEmpty() {
		return number_of_friend == 0 ? true : false;
	}
};

void find_sheet(vector<bool>& check,vector<HaveFriends>& fri, const int stu_num, int idx,int pair_num, int& goal_num) {
	/*cout << "idx: " << idx << ", pair: "<< pair_num<< endl;
	for (int i = 0; i < stu_num; i++) {
		cout << "학생" << i << ": " << check[i] << endl;
	}*/

	if (idx >= stu_num)
		return;

	if (fri[idx].isEmpty())
		return;

	if (pair_num == stu_num/2) {
		++goal_num;
	}
	else {
		if (check[idx]) //이미 짝이 있으면 넘어감
			find_sheet(check, fri, stu_num, ++idx, pair_num, goal_num);
		else {
			for (int i = idx + 1; i < stu_num; i++) {
				if (!check[i] && fri[idx].friendID[i]) {
					check[idx] = true;
					check[i] = true;

					find_sheet(check, fri, stu_num, idx+1, pair_num+1, goal_num);

					check[idx] = false;
					check[i] = false;

				}
			}
		}
	}
		

}

int main() {
	int case_num;
	int fri_num;
	int stu_num;
	int a; int b;
	int goal_num =0;
	

	cin >> case_num;

	for (int i=0; i<case_num ; i++) {
		cin >> stu_num >> fri_num;
		vector<bool> check(stu_num, false); // 일차원에 짝이되면 true로 저장
		vector<HaveFriends> num_friend;

		for (int j = 0; j < stu_num; j++) {
			num_friend.push_back(HaveFriends(stu_num));
		}

		for (int j = 0; j < fri_num; j++) {
			cin >> a >> b;
			num_friend[a].AddFriend(b);
			num_friend[b].AddFriend(a);
		}
		
		find_sheet(check, num_friend, stu_num, 0,0 ,goal_num);
		cout << goal_num << endl;
		goal_num = 0;
	}
	return 0;
}
