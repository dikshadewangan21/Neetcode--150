class MedianFinder {
public:
    priority_queue<int> left; // Max heap: smaller half
    priority_queue<int, vector<int>, greater<int>> right; // Min heap: larger half

    MedianFinder() {
    }
    
    void addNum(int num) {
        // Add number to left heap
        left.push(num);

        // Keep left's maximum <= right's minimum
        if (!right.empty() && left.top() > right.top()) {
            right.push(left.top());
            left.pop();
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        // Odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }

        // Even number of elements
        return (left.top() + right.top()) / 2.0;
    }
};