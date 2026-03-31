class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_length = 0;
        int left = 0;
        int right = 0;

        while (left <= right && right < s.size()) {
            unordered_map<char, int> char_freq;
            int window_size = right - left + 1;
            int max_freq = 0;
            char max_char;
            for (int i=left; i<=right; i++) {
                char_freq[s[i]]++;
            }
            for (auto &it : char_freq) {
                if (it.second > max_freq) {
                    max_char = it.first;
                    cout << "max_char: " << max_char << endl;
                    max_freq = it.second;
                    cout << "max_freq: " << max_freq << endl;
                }
            }
            if (window_size - max_freq <= k) {
                if (max_length < window_size) {
                    max_length = window_size;
                }
                cout << "max_length: " << max_length << endl;
                right++;
            }
            else {
                left++;
            }
        }

        return max_length;
    }
};
