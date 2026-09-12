class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;

        unordered_map<int, int> numFreq;

        for (int num : nums) {
            numFreq[num]++;
        }

        for (int i=0; i<k; i++) {
            int num = 0;
            int maxFreq = 0;
            
            for (auto it : numFreq) {
                if (it.second > maxFreq) {
                    num = it.first;
                    maxFreq = it.second;
                }
            }

            answer.push_back(num);
            numFreq.erase(num);
        }

        return answer;
    }
};
