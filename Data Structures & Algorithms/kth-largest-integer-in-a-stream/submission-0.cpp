class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }
        kth = k;
    }
    
    int add(int val) {
        pq.push(val);

        return kthLargest(kth, pq);
    }

    priority_queue<int> pq;
    int kth;

    int kthLargest(int k, priority_queue<int> pqueue) {
        vector<int> elements;
        int count = 1;

        while (count < k) {
            elements.push_back(pqueue.top());
            pqueue.pop();
            count++;
        }
    
        return pqueue.top();
    }
};
