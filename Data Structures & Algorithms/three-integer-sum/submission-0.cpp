class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;

        for (int i=0; i<nums.size(); i++) {
            int target = - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                if (target == (nums[j] + nums[k])) {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    auto it = find(triplets.begin(), triplets.end(), triplet);
                    if (it == triplets.end()) {
                        triplets.push_back(triplet);
                    }
                    j++;
                    k--;
                }
                else if (target < (nums[j] + nums[k])) {
                    k--;
                }
                else if (target > (nums[j] + nums[k])) {
                    j++;
                }
            }
        }

        return triplets;
    }
};
