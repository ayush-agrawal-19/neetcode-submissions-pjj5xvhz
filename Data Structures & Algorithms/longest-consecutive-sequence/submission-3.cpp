class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = 0;

        unordered_set<int> numbers(nums.begin(), nums.end());

        for (int num : numbers) {
            
            if (numbers.find(num-1) == numbers.end()) {
                int length = 1;

                while (numbers.find(num+length) != numbers.end()) {
                    length++;
                }

                if (length > answer) {
                    answer = length;
                }
            }
        }

        return answer;
    }
};
