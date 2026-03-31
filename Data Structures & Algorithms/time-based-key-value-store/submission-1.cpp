class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = time_map.find(key);
        if (it == time_map.end()) {
            return "";
        }

        auto &vec = it->second;

        string prev_string = "";
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (vec[mid].first > timestamp) {
                right = mid - 1;
            }
            else if (vec[mid].first < timestamp) {
                prev_string = vec[mid].second;
                left = mid + 1;
            }
            else {
                return vec[mid].second;
            }
        }

        return prev_string;
    }

private:
    unordered_map<string, vector<pair<int, string>>> time_map;
};
