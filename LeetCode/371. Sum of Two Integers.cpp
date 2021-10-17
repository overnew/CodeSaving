//https://leetcode.com/problems/sum-of-two-integers/
class Solution {
public:
	const static int max_bit = 10;

  //양수와 음수를 더하는 경우
	static int SumPosNeg(int pos, int neg) {
		bool is_sum_pos = true;
		neg *= -1;
		if (pos < neg)
			is_sum_pos = false;

		if (pos < neg)	//항상 pos가 큰 값으로 유지
			swap(pos, neg);

		int answer = 0;
		bool pos_bit, neg_bit;
		for (int bit_idx = 0; bit_idx <= max_bit ; ++bit_idx) {
			pos_bit = (pos & (1 << bit_idx));
			neg_bit = (neg & (1 << bit_idx));

			if (pos_bit != neg_bit) {
				if (!pos_bit) { 	//pos_bit =1, neg_bit = 0
					for (int i = bit_idx + 1; i <= max_bit; ++i)
						if (pos & (1 << i)) {
							pos &= ~(1 << i);
							for (int j = i - 1; j >= bit_idx + 1; --j)
								pos |= (1 << j);
						}
					answer |= (1 << bit_idx);
				}
			}
		}

		if (!is_sum_pos)
			answer *= -1;
		return answer;
	}

  //같은 부호의 값끼리 더하는 경우
	static int SumSame(int a, int b) {
		int answer = 0, n = 0;
		bool a_bit, b_bit, ceil = false;
		for (int bit_idx = 0; bit_idx <= max_bit; ++bit_idx) {
			a_bit = a & (1 << bit_idx);
			b_bit = b & (1 << bit_idx);
			n = ceil + a_bit + b_bit;
			ceil = false;
			switch (n)
			{
			case 1:
				answer |= (1 << bit_idx);
				break;
			case 2:
				ceil = true;
				break;
			case 3:
				answer |= (1 << bit_idx);
				ceil = true;
				break;
			default:
				break;
			}
		}
		if (ceil)
			answer |= (1 << (max_bit + 1));

		return answer;
	}

	int getSum(int a, int b) {
		int answer = 0;
		if (a < b)
			swap(a,b);

		if (b < 0 && a>0)
			answer = SumPosNeg(a,b);
		else {
			if (a <= 0) {
				a *= -1; b *= -1;
				answer = SumSame(a, b);
				answer *= -1;
			}
			else {
				answer = SumSame(a, b);
			}
		}
		return answer;
	}
};
