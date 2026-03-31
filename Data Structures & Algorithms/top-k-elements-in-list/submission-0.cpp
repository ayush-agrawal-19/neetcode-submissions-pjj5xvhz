class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> kFrequent;
        unordered_map<int, int> freq_num;

        for (int num : nums) {
            freq_num[num]++;
        }

        for (int i=0; i<k; i++) {
            int maxValue = 0;
            int maxFreqNum = 0;
            for (auto &it : freq_num) {
                if (it.second > maxValue) {
                    maxValue = it.second;
                    maxFreqNum = it.first;
                }
            }
            kFrequent.push_back(maxFreqNum);
            freq_num.erase(maxFreqNum);
        }
        
        return kFrequent;
    }
};
