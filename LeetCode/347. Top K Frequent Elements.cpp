struct compare {
    bool operator()(pair<int,int>& a, pair<int, int>& b) {
        return a.second < b.second;     //등장 개수로 내림차순 정렬
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (map.find(*it) == map.end())
                map[*it] = 0;

            map[*it] += 1;
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>,compare> pq;
        for (auto it = map.begin(); it != map.end(); it++)
            pq.push(*it);
        
        vector<int> ret;
        for (int i=0; i<k ;++i) {
            ret.push_back(pq.top().first);
            pq.pop();
        }

        return ret;
    }
};
