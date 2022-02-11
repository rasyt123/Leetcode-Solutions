// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> visited(nums.size(), false);
        permuthe(permutation, nums, visited, result);
        return result;



    }

    void permuthe(vector<int> permutation, vector<int>& nums, vector<bool>& visited, vector<vector<int>>& result) {
    	if (permutation.size() == nums.size()) {
    		result.push_back(permutation);
    		return;
    	}

    	for (int i = 0; i < nums.size(); i++) {
    		 if (!visited[i]) {
    		 	visited[i] = true;
    		 	permutation.push_back(nums[i]);
    		 	permuthe(permutation, nums, visited, result);
    		 	permutation.pop_back();
    		 	visited[i] = false;
    		 }

    	}


    	return;
    }
};
