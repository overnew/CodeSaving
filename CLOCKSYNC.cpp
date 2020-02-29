/*
https://algospot.com/judge/problem/read/CLOCKSYNC#c10967
vs에서 디버깅모드로 되어있고, 느려도 답이 나온다면 아마 되는 것 같습니다
릴리즈 모드로 컴파일하면 디버깅 모드보다 훨씬 빠르다고 하네요

암튼 맞게 한것 같은데 오답이라떠..
힌트는 참고한게 아쉽네여
*/

#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> button({
    vector<int>({ 0, 1, 2 }),
    vector<int>({ 3, 7, 9, 11 }),
    vector<int>({ 4, 10, 14, 15 }),
    vector<int>({ 0, 4, 5, 6, 7 }),
    vector<int>({ 6, 7, 8, 10, 12 }),
    vector<int>({ 0, 2, 14, 15 }),
    vector<int>({ 3, 14, 15 }),
    vector<int>({ 4, 5, 7, 14, 15 }),
    vector<int>({ 1, 2, 3, 4, 5 }),
    vector<int>({ 3, 4, 5, 9, 13 })
    });


void clock_syn(int num, int button_num, int& min, int clock[]) {

    if (button_num == 0) {
        for (int i = 0; i < 16; ++i) {
            if (clock[i] != 4)
                break;
            if (i == 15) {
                if (min == -1)
                    min = num;
                else
                    if (min > num)
                        min = num;
                return;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (i == 0) {
            if (button_num < 9) {
                clock_syn(num, button_num + 1, min,clock);
            }
        }
        else {
            for (int j = 0; j < button[button_num].size(); ++j) {
                ++clock[button[button_num][j]];
                if (clock[button[button_num][j]] == 5)
                    clock[button[button_num][j]] = 1;
            }
            ++num;
            for (int k = 0; k < 16; ++k) {
                if (clock[k] != 4)
                    break;
                if (k == 15) {
                    if (min == -1)
                        min = num;
                    else
                        if (min > num)
                            min = num;
                    return;
                }
            }
            if (button_num < 9 && i != 5)
                clock_syn(num, button_num + 1, min,clock);
        }
    }
    
}

int main() {
    int case_num;
    int temp;
    int num;
    int min;
    int clock[16];
    cin >> case_num;

    for (int i=0; i< case_num ;++i) {
        num = 0;
        min = -1; // -1은 안될경우

        for (int j=0; j<16 ; ++j) {
            cin >> temp;
            clock[j] =( temp / 3);
        }

        clock_syn(num, 0, min,clock);
        
        cout<< min <<endl;
    
    }

    return 0;
}
