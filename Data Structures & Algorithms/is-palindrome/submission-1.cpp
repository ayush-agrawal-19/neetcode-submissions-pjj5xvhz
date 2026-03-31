class Solution {
public:
    bool isPalindrome(string s) {
        
        if (s.empty()) {
            return true;
        }

        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalnum(c);}), s.end());
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c);});

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
