class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> char_s, char_t;

        for (char c : s) {
            auto it = char_s.find(c);
            if (it != char_s.end()) {
                char_s[c]++;
                std::cout << c << ':' << char_s[c] << endl;
            }
            else {
                char_s.insert({c, 1});
                std::cout << c << ':' << char_s[c] << endl;
            }
        }

        for (char c :t) {
            auto it = char_t.find(c);
            if (it != char_t.end()) {
                char_t[c]++;
                std::cout << c << ':' << char_t[c] << endl;
            }
            else {
                char_t.insert({c, 1});
                std::cout << c << ':' << char_t[c] << endl;
            }
        }

        if (char_s == char_t) {
            return true;
        }

        return false;
    }
};
