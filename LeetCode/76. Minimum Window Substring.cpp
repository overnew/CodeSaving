class Solution {
private:
    int numOfLetter[52];
    int windowNumOfLetter[52];
    const int UPPER_START_IDX = 26;

    int minSize = 100001;
    int min_left = 0, min_right = 0;
    int left = 0, right = 0;
    int s_len, t_len;
    string s, t;

public:
    void minusNumOfLetter(char c) {
        if ('A' <= c && c <= 'Z') {
            windowNumOfLetter[UPPER_START_IDX + (c - 'A')]--;
            return;
        }

        windowNumOfLetter[(c - 'a')]--;
    }

    void addNumOfLetter(char c, int arr[]) {
        if ('A' <= c && c <= 'Z') {
            arr[UPPER_START_IDX + (c - 'A')]++;
            return;
        }
        
        arr[(c - 'a')]++;
    }

    void calcNumOfLetter(string t) {
        for (int i=0 ; i<t_len; ++i) {
            addNumOfLetter(t[i], numOfLetter);
        }
    }

    bool checkIsHaveAllT() {
        for (int i =0; i<52; ++i) {
            if (numOfLetter[i] - windowNumOfLetter[i] > 0)
                return false;
        }

        return true; //더 많이 가지고 있어야 true
    }

    void moveRightToTakeAllT() {
        for (; right < s_len ; ++right) {
            addNumOfLetter(s[right], windowNumOfLetter);

            if (checkIsHaveAllT())
                break;
        }
    }

    string minWindow(string s, string t) {
        this->s = s; this->t = t;
        s_len = s.length(); t_len = t.length();
        if (s_len < t_len)
            return "";


        memset(numOfLetter, 0, sizeof(numOfLetter));
        memset(windowNumOfLetter, 0, sizeof(windowNumOfLetter));
        calcNumOfLetter(t);

        for (int i = 0; i < 52; ++i) {
            cout << "i: " << i << ", " << numOfLetter[i] << '\n';
        }

        moveRightToTakeAllT();

        while (right<s_len && left <= right) {

            int windowSize = right - left + 1;
            if (windowSize < minSize) {
                minSize = windowSize;
                min_left = left;
            }

            minusNumOfLetter(s[left]);
            left++;
            if (!checkIsHaveAllT()) {
                ++right;
                moveRightToTakeAllT();
            }
        }

        if (minSize == 100001)
            return "";

        return s.substr(min_left, minSize);
    }
};
