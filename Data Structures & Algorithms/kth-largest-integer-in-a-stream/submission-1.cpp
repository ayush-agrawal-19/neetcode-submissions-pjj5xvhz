class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        
        for (int num : nums) {
            pq.push(num);
        }
    }
    
    int add(int val) {
        pq.push(val);

        while (pq.size() > kth) {
            pq.pop();
        }

        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
};
