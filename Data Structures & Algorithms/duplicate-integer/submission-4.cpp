class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> visited;

        for (int num : nums) {
            if (visited.contains(num)) {
                return true;
            }
            else {
                visited[num] = 1;
            }
        }

        return false;
    }
};