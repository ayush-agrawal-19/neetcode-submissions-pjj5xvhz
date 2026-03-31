class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ind;
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            if ((numbers[left]+numbers[right]) == target) {
                ind.push_back(left+1);
                ind.push_back(right+1);
                return ind;
            }
            else if ((numbers[left]+numbers[right]) >= target) {
                right--;
            }
            else if ((numbers[left]+numbers[right]) <= target) {
                left++;
            }
        }

        return ind;
    }
};
