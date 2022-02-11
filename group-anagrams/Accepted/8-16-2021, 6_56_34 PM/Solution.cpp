// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
       map<string, vector<string>> container;
       vector<vector<string>> sortedstrings;
       string sortedver;
       string unsortedver;
       for(string item : strs) {
           unsortedver = item;
           sortedver = item;
           sort(sortedver.begin(), sortedver.end());
           if (container.find(sortedver) == container.end()) {
               vector<string> subvec = {unsortedver};
               container[sortedver] = subvec; 
           } else {
               container[sortedver].push_back(unsortedver);
           }
       } 
        
        for (auto item : container) {
            sortedstrings.push_back(item.second);
        }
        
        return sortedstrings;
        
       /*
       
       I can solve this but I want to 
       Brute force Solution 
       Create a Vector that holds one set of anagrams 
       
       compare the anagram at index i with the rest of
       the anagrams if they are the same add it to the vector
       o(n^2)
                
                
       What would I use a hashtable for here?
       "ate", "eat", "bat", "nat", "tan", "tea"
       
       
       
       Second solution
       This is O(n)
       Sort each string in strs to be in alphabetical order 
       Hashtable with vector of strings in each
       
       ate  eat tea ate 
       atn  tan nat 
       abt bat
       
       create a vector of vector of strings
       
       for each item in strs:
           string = sorted version at item
           if it doesnt exist in the hashtable:
               add the key
               add the unsorted version into the vector of strings
           otherwise if it exists in the hastable:
               add the unosrted version to the vector of strings
       for each item in the hastable:
            add it into the vector of strings
       
         
       
       */
    }
};