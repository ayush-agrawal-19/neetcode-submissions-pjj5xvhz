class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string num : tokens) {
            if (num == "+") {
                int one = nums.top();
                nums.pop();
                int two = nums.top();
                nums.pop();
                nums.push(one + two);
            }
            else if (num == "-") {
                int one = nums.top();
                nums.pop();
                int two = nums.top();
                nums.pop();
                nums.push(two - one);
            }
            else if (num == "*") {
                int one = nums.top();
                nums.pop();
                int two = nums.top();
                nums.pop();
                nums.push(one * two);
            }
            else if (num == "/") {
                int one = nums.top();
                nums.pop();
                int two = nums.top();
                nums.pop();
                nums.push(two / one);
            }
            else {
                nums.push(stoi(num));
            }
        }

        return nums.top();
    }
};
