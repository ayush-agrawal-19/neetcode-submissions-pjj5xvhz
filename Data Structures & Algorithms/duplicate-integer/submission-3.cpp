class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> duplicates;

        for (int num : nums) {
            if (duplicates.contains(num)) {
                return true;
            }
            else {
                duplicates.insert(num);
            }
        }

        return false;
    }
};