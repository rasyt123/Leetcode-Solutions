// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        map<char, Trie*> children;
        bool endofword = false;
        prefixchecker = nullptr;

    }
    map<char, Trie*> children;
    bool endofword;
    Trie* prefixchecker;
    /** Inserts a word into the trie. */
    void insert(string word) {
        /*
        Want to insert a b c

        */
        Trie* newnode;
        Trie* temp;
        newnode = this;
        if (children.count(word[0]) == 0) {
            newnode = new Trie;
            newnode->endofword = false;
            children[word[0]] = newnode;
            newnode = this;
        }

        for (int i = 0; i < word.size(); i++) {
            if (newnode->children.count(word[i]) != 0) {
                newnode = newnode->children[word[i]];
                if (i == word.size() - 1) {
                    newnode->endofword = true;
                }
            } else {
                temp = new Trie;
                temp->endofword = false;
                newnode->children[word[i]] = temp;
                newnode = temp;
            }
        }
        temp->endofword = true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0;
        Trie* newnode;
        newnode = this;
        while (i < word.size())  {
            if (newnode->children.count(word[i]) != 0) {
                newnode = newnode->children[word[i]];
            } else {
                return false;
            }
            i++;
        }
        if (!newnode->endofword and i == word.size()) {
            return false;
        }
        prefixchecker = newnode;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //I need to go to the last item in the prefix's hashmap and check if it is empty
        int i = 0;
        Trie* newnode;
        newnode = this;
        while (i < prefix.size()) {
            if (newnode->children.count(prefix[i]) != 0) {
                newnode = newnode->children[prefix[i]];
            } else {
                return false;
            }
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */