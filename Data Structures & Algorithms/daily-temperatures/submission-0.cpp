class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size(), 0);
        stack<int> temp_ind;

        for (int i=0; i<temperatures.size(); i++) {
            while (!temp_ind.empty() && temperatures[temp_ind.top()] < temperatures[i]) {
                    days[temp_ind.top()] = i - temp_ind.top();
                    temp_ind.pop();
                }
                temp_ind.push(i);
        }

        return days;
    }
};
