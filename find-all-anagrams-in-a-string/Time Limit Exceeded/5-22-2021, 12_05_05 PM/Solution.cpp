// https://leetcode.com/problems/find-all-anagrams-in-a-string



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        string substringz;
        bool anagramtrue;
        vector<int> startindices;
        for (int i = 0; i <= s.size() - 1; i++) {
            for (int j = 0; j <= p.size(); j++) {
                substringz = s.substr(i, j);
                if (p.size() == substringz.size()) {
                    std::cout << substringz << endl;
                    anagramtrue = AnagramChecker(p, substringz);
                    if (anagramtrue) {
                        startindices.push_back(i);
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return startindices;
    }

    bool AnagramChecker(const string& original, string& subberstring);
};


bool Solution::AnagramChecker(const string& original, string& subberstring) {
    bool anagramfound;
    bool letterfound = false;
    for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < subberstring.size(); j++) {
            if (original.at(i) == subberstring.at(j)) {
                letterfound = true;
                subberstring.at(j) = 'X';
                break;
            }
        }
        if (!letterfound) {
            return false;
        } else {
            letterfound = false;
        }
    }
    return true;
}

