class TryNode {
private:
    bool endFlag = false;
    bool haveChild = false;
    TryNode* children[26] = {};

public:
    TryNode() {
        endFlag = false;
        haveChild = false;
    }

    void insertNode(string word, int depth) {
        if (word.size() <= depth) {
            this->endFlag = true;
            return;
        }

        this->haveChild = true;
        char nextChar = word[depth];
        TryNode* next = this->children[nextChar - 'a'];
        if (next == nullptr) {
            next = new TryNode();
            this->children[nextChar - 'a'] = next;
        }

        next->insertNode(word, depth +1);
        return;
    }

    bool searchWithDot(string word, int depth) {
        if (word.size() <= depth) {
            return this->endFlag;
        }

        TryNode* next;
        if (word[depth] == '.') {
            if (!this->haveChild)
                return false;

            for (int i=0; i<26 ; ++i) {
                next = this->children[i];
                if (next == nullptr)
                    continue;

                if (next->searchWithDot(word, depth+1))
                    return true;
            }

            return false;
        }
            
        next = this->children[word[depth] - 'a'];
        if (next != nullptr) {
            return next->searchWithDot(word, depth + 1);
        }
        return false;
    }
};

class WordDictionary {
private:
    TryNode* rootNode;
public:
    WordDictionary() {
        rootNode = new TryNode();
    }

    void addWord(string word) {
        rootNode->insertNode(word, 0);
    }

    bool search(string word) {
        return rootNode->searchWithDot(word, 0);
    }
};
