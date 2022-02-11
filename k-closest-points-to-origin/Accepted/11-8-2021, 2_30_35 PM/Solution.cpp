// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
        From the origin, we first loop through the vector of vector of points
        and then calculate the distances from the origin. We can create 
        a pair with the distances and the points, and push them onto a priority queue,
        but with the distances as the first argument, so the points with the smallest distance from the origin are up first
        
        
        we then pop each of the elements from the priority queue one by one, decrementing a variable equal to k 
        until it reaches zero 
        */
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        vector<vector<int>> finalvec;
        double distance;
        int j = k;
        for (int i = 0; i < points.size(); i++) {
           distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
           pair<double, vector<int>> newp = {distance, points[i]};
           pq.push(newp);
        }
        while (!pq.empty()) {
            if (j == 0) {
                break;
            }
            finalvec.push_back(pq.top().second);
            pq.pop();
            --j;
        }
        
        return finalvec;
        
      
        
        
    }
};