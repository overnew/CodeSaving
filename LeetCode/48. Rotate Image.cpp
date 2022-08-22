class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		for (int shellIdx=0; shellIdx< (matrix.size()+1)/2; ++shellIdx) {
			int shellSize = matrix.size() - (2 * shellIdx);
			int shellColumnLimit = (matrix.size() - 1) - shellIdx;
			int shellRowLimit = shellColumnLimit;

			for (int dist = 0; dist < shellSize -1; ++dist) {
				int temp = matrix[shellIdx][shellIdx + dist];
				matrix[shellIdx][shellIdx + dist] = matrix[shellRowLimit - dist][shellIdx];
				matrix[shellRowLimit - dist][shellIdx] = matrix[shellRowLimit][shellColumnLimit -dist];
				matrix[shellRowLimit][shellColumnLimit - dist] = matrix[shellIdx +dist][shellColumnLimit];
				matrix[shellIdx + dist][shellColumnLimit] = temp;
			}
		}
		
    }

};
