class Solution {
public:
    void sortPairs(vector<pair<string, string>>& pairs){
        for (int i=0; i< pairs.size(); ++i) {   //first 원소만 정렬
            sort(pairs[i].first.begin(), pairs[i].first.end());
        }
        sort(pairs.begin(), pairs.end()); // 전체 vector 정렬
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if (strs.size() == 1) {     //size가 1일때
            ret.push_back({ strs[0] });
            return ret;
        }

        vector<pair<string, string>> pairs; //strs 복사
        for (int i=0; i<strs.size(); ++i) {
            pairs.push_back({strs[i], strs[i]});
        }

        sortPairs(pairs);
        for (int i = 0; i < pairs.size(); ++i) {
            cout << pairs[i].first << ", " << pairs[i].second << '\n';
        }

        string matchWord = pairs[0].first;
        vector<string> matchWords = { pairs[0].second};
        for (int i = 1; i < pairs.size(); ++i) {
            if (matchWord.compare(pairs[i].first) == 0) {
                matchWords.push_back(pairs[i].second);
                continue;
            }

            ret.push_back(matchWords);
            if (i >= pairs.size())
                return ret;

            matchWord = pairs[i].first;
            matchWords = vector<string>{pairs[i].second};  //초기화
        }
        if (!matchWords.empty())
            ret.push_back(matchWords);

        return ret;
    }
};
