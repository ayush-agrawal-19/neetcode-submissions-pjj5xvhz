class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> differences;

        for (int i=0; i<nums.size(); i++) {
            int difference = target - nums[i];
            if (differences.find(difference) != differences.end()) {
                return {differences[difference], i};
            }
            differences.insert({nums[i], i});
        }

        return {};
    }
};
