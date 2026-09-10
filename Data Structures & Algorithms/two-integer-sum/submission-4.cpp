class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> sum;
        vector<int> answer;

        for (int i=0; i<nums.size(); i++) {
            sum[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            int num = target - nums[i];

            auto it = sum.find(num);

            if (it != sum.end()) {
                if (it->second != i) {
                    answer.push_back(i);
                    answer.push_back(it->second);
                    break;
                }
            }
        }

        return answer;
    }
};
