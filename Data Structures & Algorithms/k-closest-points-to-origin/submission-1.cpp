class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closestPoints;
        priority_queue<pair<double, vector<int>>> closestDist;

        for (vector<int> point : points) {
            double dist = sqrt((point[0]*point[0]) + (point[1]*point[1]));
            cout << "point: [" << point[0] << "," << point[1] << "] dist: " << dist << endl;
            closestDist.push({dist, point});
            if (closestDist.size() > k) {
                closestDist.pop();
            }
        }

        while(!closestDist.empty()) {
            pair<double, vector<int>> point = closestDist.top();
            closestDist.pop();
            closestPoints.push_back(point.second);
        }

        return closestPoints;
    }
};
