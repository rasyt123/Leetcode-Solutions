// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
public:
    /** Initialize your data structure here. */
   map<char, WordDictionary*> children;
    bool endofword;

    WordDictionary() {
        map<char, WordDictionary*> children;
        bool endofword = false;


    }

    void addWord(string word) {
        WordDictionary* newnode;
        WordDictionary* temp;
        newnode = this;
        if (word.size() == 1 and children.count(word[0]) != 0) {
            return;
        }
        if (children.count(word[0]) == 0) {
            newnode = new WordDictionary;
            children[word[0]] = newnode;
            newnode = this;
        }
        for (int i = 0; i < word.size(); i++) {
            if (newnode->children.count(word[i]) != 0) {
                newnode = newnode->children[word[i]];
            } else {
                temp = new WordDictionary;
                newnode->children.insert({word[i], temp});
                newnode = temp;
            }
        }
        return;
    }

     bool search(string word) {
        WordDictionary* newnode;
        newnode = this;
        for (int i = 0; i < word.size(); i++) {
            if (newnode->children.count(word[i]) != 0) {
                newnode = newnode->children[word[i]];
            } else if (word[i] == '.') {
                if (newnode->children.empty()) {
                    return false;
                }
                for (pair<char, WordDictionary*> item: newnode->children) {
                    if (!newnode->children.empty() and item.first != word[i]) {
                        newnode = newnode->children[item.first];
                        break;
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */