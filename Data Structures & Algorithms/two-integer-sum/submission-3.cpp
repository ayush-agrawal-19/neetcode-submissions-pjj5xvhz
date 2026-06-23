class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> index;
        vector<int> answer;

        for (int i=0; i<nums.size(); i++) {
            index[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];

            auto it = index.find(diff);

            if (it != index.end()) {
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
