int visited[12][12];
pair<int, int> movePos[4] = { {0,1},{1,0},{0,-1}, {-1,0} };

class TrieNode {
public:
    TrieNode* children[26] = {};
    string* end_word;

    TrieNode() { end_word = nullptr; }

    void insertWord(string& word) {
        TrieNode* node = this;
        for (size_t i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }
        node->end_word = &word;
    }

};

class Solution {
public:
    TrieNode* root;
    vector<string> foundWords;
    int boardRow, boardCol;

    Solution() {
        root = new TrieNode();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        boardRow = board.size();
        boardCol = board[0].size();

        for (string& word : words)
            root->insertWord(word);

        for (size_t r = 0; r < boardRow; r++)
            for (size_t c = 0; c < boardCol; c++)
                if(root->children[board[r][c] -'a'] != nullptr)
                    findWordInTrie(board, root->children[board[r][c] - 'a'],r,c);

        return foundWords;
    }

    void findWordInTrie(vector<vector<char>>& board,  TrieNode* node,int row, int col) {

        if (node->end_word != nullptr) {
            foundWords.push_back(*node->end_word);
            node->end_word = nullptr;     //중복 search방지
        }

        visited[row][col] = 1;
        int next_r = row;
        int next_c = col;

        for (int dir = 0; dir < 4; ++dir) {
            next_r = row + movePos[dir].first;
            next_c = col + movePos[dir].second;

            if (( 0<= next_r && next_r< boardRow) && (0 <= next_c && next_c < boardCol) && visited[next_r][next_c] == 0) {

                int next_char_idx = board[next_r][next_c] - 'a';
                TrieNode* nextNode = node->children[next_char_idx];

                if (nextNode == nullptr)
                    continue;
                
                findWordInTrie(board,  nextNode, next_r, next_c);
            }
        }

        visited[row][col] = 0;
        return;
    }
};
