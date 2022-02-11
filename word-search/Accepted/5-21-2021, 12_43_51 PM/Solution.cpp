// https://leetcode.com/problems/word-search

#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int prevrow;
        int prevcol;
        bool firstitem = false;
        string unedited;
        string checker;
        bool match = false;
        bool* foundmatch;
        bool foundword;
        foundmatch = &match;
        unedited = word;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                if (board[i][j] == word[word.size() - 1]) {
                    if (word.size() == 1) {
                        return true;
                    } else {
                        foundword = WordSearch(board, word, i, j, foundmatch, unedited);
                        if (*foundmatch == true) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
private:
    bool WordSearch(vector<vector<char>>& board, string word, int row, int column, bool* foundmatch, string& unedited);
};


bool Solution::WordSearch(vector<vector<char>>& board, string word, int row, int column, bool* foundmatch, string& unedited) {
        if (row < 0 or column < 0 or row > board.size() - 1 or column > board.at(0).size() - 1) {
            return false;
        }
        if (word.empty()) {
            *foundmatch = true;
            return true;
        }
        else if (board[row][column] == word.at(word.size() - 1)) {
            std::cout << word << endl;
            word.pop_back();
            board[row][column] = '#';
            WordSearch(board, word, row - 1, column, foundmatch, unedited);
            WordSearch(board, word, row + 1, column, foundmatch, unedited);
            WordSearch(board, word, row, column - 1, foundmatch, unedited);
            WordSearch(board, word, row, column + 1, foundmatch, unedited);
        } else {
            return false;
        } 
   
    return false;
}
