class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> arr_nums;
        int longest_seq = 0;
        
        for (int num : nums) {
            arr_nums.insert(num);
        }

        for (int num : arr_nums) {
            auto it = arr_nums.find(num-1);
            if (it != arr_nums.end()) {
                continue;
            }
            else {
                vector<int> seq;
                seq.push_back(num);
                int next_num = num + 1;
                auto iter = arr_nums.find(next_num);
                while (iter != arr_nums.end()) {
                    seq.push_back(next_num);
                    next_num++;
                    iter = arr_nums.find(next_num);
                }
                if (seq.size() > longest_seq) {
                    longest_seq = seq.size();
                }
            }
        }

        return longest_seq;

    }
};
