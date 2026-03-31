class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closest;
        priority_queue<pair<int, vector<int>>> distances;

        for (vector<int> point : points) {
            int dist = point[0]*point[0] + point[1]*point[1];
            distances.push({dist, point});

            if (distances.size() > k) {
                distances.pop();
            }
        }

        while (!distances.empty()) {
            closest.push_back(distances.top().second);
            distances.pop();
        }

        return closest;
    }
};
