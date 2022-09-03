class Solution {
public:
	int characterReplacement(string s, int k) {
		int maxLen = 0;	//정답의 최대 길이
		vector<int> letterCount(26,0);
		
		int left = 0, right = 0, windowSize = 0;
		int maxFrequency = 0;

		for ( ; right< s.length(); ++right) {

			++letterCount[s[right] - 'A']; //윈도우를 오른쪽으로 한칸 늘림
			maxFrequency = max(maxFrequency, letterCount[s[right] - 'A']);	//추가된 문자로 인한 maxFreq 업데이트

			windowSize = right - left + 1;
			if (windowSize - maxFrequency > k) {	//해당 윈도우에서는 더이상 k개 변환으로 모든 문자가 같아질 수 없을때

				maxLen = max(maxLen, windowSize -1);	//이전 크기로 비교
				
				//윈도우의 왼쪽을 한칸 줄임
				--letterCount[s[left] - 'A'];
				maxFrequency = max(maxFrequency, letterCount[s[left] - 'A']);	//윈도우에서의 최대 빈도 수 업데이트
				++left; 
			}

		}

		return max(maxLen , right -left);	//K이하의 문자가 변경는 경우 대비
	}
};
