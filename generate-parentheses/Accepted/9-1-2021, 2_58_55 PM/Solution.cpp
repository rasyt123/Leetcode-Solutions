// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        string base = "()";
        string builder;
        for (int i = 0; i < n; i++) {
            builder += base;
        }
        dfs(0, combinations, builder, n);
        return combinations;
    }

    void dfs(int currindex, vector<string>& combinations, string currstr, int n) {
        char original = currstr[currindex];
        if (isbalanced(currstr) and currindex == 2 * n) {
            combinations.push_back(currstr);
            return;
        }

        if (currindex == 2 * n) {
            return;
        }

        if (currstr[currindex] == '(') {
            currstr[currindex] = ')';
        } else {
            currstr[currindex] = '(';
        }
        dfs(currindex + 1, combinations, currstr, n);
        currstr[currindex] = original;
        dfs(currindex + 1, combinations, currstr, n);
    }



   bool isbalanced(string currstr) {
    	stack<char> balanced;
    	for (int i = 0; i < currstr.size(); i++) {
    		if (currstr[i] == '(') {
    			balanced.push('(');
    		} else {
    			if (balanced.empty()) {
    				return false;
    			} else if (currstr[i] == ')') {
    				balanced.pop();
    			}
    		}
    	}

    	if (!balanced.empty()) {
    		return false;
    	} else {
    		return true;
    	}
    }
};