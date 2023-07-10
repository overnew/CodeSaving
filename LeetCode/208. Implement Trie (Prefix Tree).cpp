class TryNode {
private:
    bool endFlag = false;
    TryNode* children[26] = {};

public:
    TryNode() {
        endFlag = false;
    }

    void insertNode(string word, int depth) {
        if (word.size() <= depth) {
            this->endFlag = true;
            return;
        }

        char nextChar = word[depth];
        TryNode* next = this->children[nextChar - 'a'];
        if (next == nullptr) {
            next = new TryNode();
            this->children[nextChar - 'a'] = next;
        }

        next->insertNode(word, depth +1);
        return;
    }

    bool searchPrefix(string word, int depth) {
        if (word.size() <= depth)
            return true;

        TryNode* next = this->children[word[depth] - 'a'];
        if (next != nullptr) {
            return next->searchPrefix(word, depth + 1);
        }
        return false;
    }

    bool searchWord(string word, int depth) {
        if (word.size() <= depth ) {
            return this->endFlag;
        }

        TryNode* next = this->children[word[depth] - 'a'];
        if (next != nullptr) {
            return next->searchWord(word, depth+1);
        }
        return false;
    }
};

class Trie{
private:
    TryNode* rootNode;

public:
    Trie() {
        rootNode = new TryNode();
    }

    void insert(string word) {
        rootNode->insertNode(word,0);
    }

    bool search(string word) {
        return rootNode->searchWord(word, 0);
    }

    bool startsWith(string prefix) {
        return rootNode->searchPrefix(prefix,0);
    }
};
