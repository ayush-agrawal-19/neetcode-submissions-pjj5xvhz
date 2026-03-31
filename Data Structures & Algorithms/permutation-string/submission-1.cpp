class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        if (s1.empty()) {
            return true;
        }

        vector<int> substring(26,0);
        string substr;

        for (char c : s1) {
            substring[c - 'a']++;
        }

        for (int i : substring) {
            substr += to_string(i);
        }

        int left = 0;
        int right = s1.size() - 1;

        while (right < s2.size()) {
            vector<int> permutation(26,0);
            string perm;
            for (int i=left; i<=right; i++) {
                permutation[s2[i] - 'a']++;
            }
            for (int i : permutation) {
                perm += to_string(i);
            }
            if (perm == substr) {
                return true;
            }
            left++;
            right++;
        }

        return false;
    }
};
