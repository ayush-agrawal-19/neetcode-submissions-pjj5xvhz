class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;

        int index1 = 0;
        int index2 = numbers.size() - 1;

        while (index1 < index2) {
            int sum = numbers[index1] + numbers[index2];

            if (sum == target) {
                answer.push_back(index1+1);
                answer.push_back(index2+1);
                break;
            }
            else if (sum > target) {
                index2--;
            }
            else {
                index1++;
            }
        }

        return answer;
    }
};
