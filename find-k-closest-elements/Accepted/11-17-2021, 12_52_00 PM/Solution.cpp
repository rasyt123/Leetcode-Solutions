// https://leetcode.com/problems/find-k-closest-elements

bool comparator(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first == p2.first) {
            if (p1.second < p2.second) {
                return true;
            }  else {
                return false;
            }     
        } else {
            return false;
        }
    }


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
        
        Today: 
        An integer a is clsoer to x if a - x == b - x and a < b 
        
        
        Custom sorter 
        
        if pair1.first < pair2.second:
            retutrn true;
            if pair1.first == pair2.first:
                if pair1.second < pair2.second:
                    return true;
                otherwise:
                    return false
            else 
                return false
            
             
            
        
        {1:-2  2:-1 3:0 4: 1 5: 2}
        {(0, 3), (1, 2), (1, 4), (2, 1), (2, 5)}
        
        
        Make pairs of the a -x at every single element 
        sort the pairs
        then iterate through the pairs and decrement k until its zero 
        and push the pairs into a priority queue
                    
        
        */
    
        vector<int> newvec;
        vector<pair<int, int>> closestpairs;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
        for (int i = 0; i < arr.size(); i++) {
            closestpairs.push_back({abs(arr[i] - x), arr[i]});
        }
        sort(closestpairs.begin(), closestpairs.end(), comparator);
        
        for (int i = 0; i < k; i++) {
            cout << "{" << closestpairs[i].first << ", " << closestpairs[i].second << "}" << endl;
            newvec.push_back(closestpairs[i].second);
        }
        sort(newvec.begin(), newvec.end());
        return newvec;
        
    }
};