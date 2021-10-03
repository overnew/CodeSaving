class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int sell = -1 , buy = 10001;
		int max_gap = 0;
		for (int day = prices.size()-1; day>=0 ; --day) {
			if (prices[day] > sell) {
				sell = buy = prices[day];
			}
			else if (prices[day] < buy) {
				buy = prices[day];
				max_gap = max(max_gap, sell - buy);
			}
		}
		return  max_gap;
    }
};
