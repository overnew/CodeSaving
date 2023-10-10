class Solution {
public:

	//각 수가 최대 10^6을 나타낼 수 있으므로 2^20 범위까지 1로 채움
	int makeAllBitOneNum() {	
		int ret = 1;
		int move_bit = 1;
		for (int i= 1; i<=21; ++i) {
			ret |= (move_bit << i);
		}

		return ret;
	}


	int maxSubarrays(vector<int>& nums) {
		const int allOneBits = makeAllBitOneNum();
		int conti_bits = allOneBits;
		
		int subArr_num = 0;

		for (int i = 0; i< nums.size(); ++i) {
			conti_bits &= nums[i];

			if (!conti_bits) {	//AND로 0이 만들어진 경우 arr 분리
				++subArr_num;
				conti_bits = allOneBits;
			}
		}

		if (subArr_num == 0)	//AND가 0으로 만들지 못하는 경우
			return 1;

		return subArr_num;
	}
};
