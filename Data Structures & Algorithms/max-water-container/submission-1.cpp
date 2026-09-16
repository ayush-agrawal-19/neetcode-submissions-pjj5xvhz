class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer = 0;

        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int area = (right - left) * min(heights[left], heights[right]);

            if (area > answer) {
                answer = area;
            }

            if (heights[right] > heights[left]) {
                left++;
            }
            else {
                right--;
            }
        }

        return answer;
    }
};
