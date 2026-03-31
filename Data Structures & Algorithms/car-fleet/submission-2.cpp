class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> fleets;
        vector<pair<int, int>> pos_spd;
        vector<float> times;

        for (int i=0; i<position.size(); i++) {
            pos_spd.push_back({position[i], speed[i]});
        }
        // for (auto it : pos_spd) {
        //     cout << it.first << ":" << it.second << " ";
        // }
        // cout << endl;

        sort(pos_spd.begin(), pos_spd.end(), greater<pair<int, int>>());
        // for (auto it : pos_spd) {
        //     cout << it.first << ":" << it.second << " ";
        // }
        // cout << endl;

        for (auto it : pos_spd) {
            times.push_back((target - it.first) / (float)it.second);
        }

        // for (int i=0; i<times.size(); i++) {
        //     cout << times[i] << " ";
        // }
        // cout << endl;

        for (int i=0; i<times.size(); i++) {
            if (fleets.empty() || times[i] > fleets.top()) {
                fleets.push(times[i]);
                cout << "value pushed: " << times[i] << endl;
            }
        }

        return fleets.size();
    }

};
