using namespace std;
using ll = long long;

class Solution {
public:
	bool binarySearch(ll alloyNum,int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
		ll minCost = LONG_MAX;
		
		for (vector<int> machineComposition : composition) {	//2중 for문은 보기 힘드니까 foreach로
			ll extraCost = 0;
			
			for (int i =0; i<machineComposition.size(); ++i) {
				ll needComposNum = alloyNum * machineComposition[i];
				if (stock[i] >= needComposNum) {
					continue;
				}
				else {
					ll costToBuy = (needComposNum - stock[i]) * cost[i];
					extraCost += costToBuy;
				}
			}

			minCost = min(minCost, extraCost);
		}

		return (minCost <= budget);
	}

	int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
		int low = 0, high = 1e9;
		
		int res = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			//mid == 만들 alloy의 목표 개수

			if (binarySearch(mid, budget, composition, stock, cost)) {
				//mid 개수가 예산 범위 내인 경우 
				low = mid + 1;
				res = max(res, mid);
			}
			else {
				high = mid - 1;
			}
		}

		return res;
	}
};
