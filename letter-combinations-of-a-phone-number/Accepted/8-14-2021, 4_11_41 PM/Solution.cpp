// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> phonenums{{'2', "cba"}, {'3', "fed"}, {'4', "ihg"}, {'5', "lkj"}, {'6', "onm"}, {'7', "srqp"}, {'8', "vut"}, {'9', "zyxw"}};
        vector<string> combos;

        recursivehelper(0, 0, digits, phonenums, combos, digits);
        sort(combos.begin(), combos.end());
        return combos;
    }

    bool is_alpha(const std::string &str)
    {
        return std::all_of(str.begin(), str.end(), ::isalpha); // C++11
    }

    void recursivehelper(int index, int numindex, string digits, map<char, string>& phonenums, vector<string>& combos, string& digits2) {
        if (index >= digits.size() or numindex >= phonenums[digits2[index]].size()) {
            return;
        }
        digits[index] = phonenums[digits2[index]][numindex];
        if (is_alpha(digits)) {
            combos.push_back(digits);
        }
        recursivehelper(index, numindex + 1, digits, phonenums, combos, digits2);
        numindex = 0;
        recursivehelper(index + 1, numindex, digits, phonenums, combos, digits2);

    }
};