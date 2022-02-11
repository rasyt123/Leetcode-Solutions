// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        /*
        We insert all the items into a hashtable called freqmap
        We need to use a max heap to sort the keys by their frequencies
        pair<int, char>
        */
        priority_queue<pair<int, char>> pq;
        string result;
        map<char, int> freqmap;
        for (int i = 0; i < s.size(); i++) {
            ++freqmap[s[i]];
        }
        for (pair<char, int> item : freqmap) {
            pair<int, char> newitem = {item.second, item.first};
            pq.push(newitem);
        }
        
        while (!pq.empty()) {
            pair<int, char> newitem = pq.top();
            for (int i = 0; i < newitem.first; i++) {
                result.push_back(newitem.second);
            }
            pq.pop();
        }
        return result;
        
    }
};