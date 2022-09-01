class Solution {
	bool visited[6][6];
	int addDir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };

public:
    bool exist(vector<vector<char>>& board, string word) {
		memset(visited, false, sizeof(visited));
		int idx = 0;

		for (int r=0; r<board.size(); ++r) {
			for (int c = 0; c<board[0].size(); ++c) {
				if (board[r][c] == word[0]) {
					visited[r][c] = true;
					if (dfsSearchAdjaction(board, word, idx, r, c))
						return true;
					visited[r][c] = false;
				}
			}
		}

		return false;

    }

	bool dfsSearchAdjaction(vector<vector<char>>& board, string word, int idx, int stdRow, int stdCol) {
		if (idx >= word.size() -1)
			return true;

		int maxRow = board.size(), maxCol = board[0].size();

		for (int i = 0; i < 4; i++)
		{
			int nextRow = stdRow + addDir[i][0];
			int nextCol = stdCol + addDir[i][1];

			if (checkBoundary(nextRow, nextCol, maxRow, maxCol) &&
				!visited[nextRow][nextCol]  && word[idx + 1] == board[nextRow][nextCol]) {
				visited[nextRow][nextCol] = true;

				if (dfsSearchAdjaction(board, word, idx+1, nextRow, nextCol))
					return true;

				visited[nextRow][nextCol] = false;
			}
		}

		return false;
	}

	bool checkBoundary(int row, int col ,int maxRow, int maxCol) {
		if (row >= 0 && row < maxRow && col >= 0 && col < maxCol)
			return true;
		
		return false;
	}
};
