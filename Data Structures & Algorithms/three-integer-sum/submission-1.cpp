class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-2; i++) {
            int target = -nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                vector<int> zerosum;
                if (nums[left]+nums[right] == target) {
                    zerosum.push_back(nums[i]);
                    zerosum.push_back(nums[left]);
                    zerosum.push_back(nums[right]);
                    if (find(answer.begin(),answer.end(), zerosum) == answer.end()) {
                        answer.push_back(zerosum);
                    }
                    left++;
                    right--;
                }
                else if (nums[left]+nums[right] < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return answer;
    }
};
