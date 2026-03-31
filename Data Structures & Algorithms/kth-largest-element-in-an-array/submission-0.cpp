class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kthLargest;

        for (int i=0; i<nums.size(); i++) {
            kthLargest.push(nums[i]);

            if (kthLargest.size() > k) {
                kthLargest.pop();
            }
        }

        return kthLargest.top();
    }
};
