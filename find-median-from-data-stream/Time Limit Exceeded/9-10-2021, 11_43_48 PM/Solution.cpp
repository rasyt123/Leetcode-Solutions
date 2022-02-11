// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */

    /*
    Use minheap to add the numbers
    we need to keep track of the size of the minheap
    if the size is odd, then we do n / 2

    we keep popping until n / 2

    1 2 3 4 5 6
    0 1 2 3 4 5
    n/2, n/2 + 1
    */
    int currsize;
    priority_queue<double, vector<double>, greater<double>> pq;
    stack<double> items;
    MedianFinder() {
        int currsize;
        priority_queue<double, vector<double>, greater<double>> pq;
        stack<double> items;
    }

    void addNum(int num) {
        pq.push(num);
        currsize = pq.size();
    }

    double findMedian() {
        if (currsize % 2 != 0) {
            int upto = currsize / 2;
            //1 2 3
            int start = 0;
            while (start < upto) {
                int result = pq.top();
                pq.pop();
                items.push(result);
                ++start;
            }
            double median = pq.top();
            while (!items.empty()) {
                int topitem = items.top();
                pq.push(topitem);
                items.pop();
            }
            return median;
        } else {
            int upto = currsize / 2;
            int start = 0;
            while (start < upto) {
                int result = pq.top();
                pq.pop();
                items.push(result);
                ++start;
            }
            double midval1 = items.top();
            double midval2 = pq.top();
            double median = (midval1 + midval2) / 2;
            while (!items.empty()) {
                int topitem = items.top();
                pq.push(topitem);
                items.pop();
            }
            return median;
        }


    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */