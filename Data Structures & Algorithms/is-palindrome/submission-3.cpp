class Solution {
public:
    bool isPalindrome(string s) {
        
        int index = 0;
        while (index < s.size()) {
            if (!isalnum(s[index])) {
                s.erase(index, 1);
            }
            else {
                index++;
            }
        }

        for (int i=0; i<s.size(); i++) {
            s[i] = tolower(s[i]);
        }

        cout << s << endl;

        int i = 0;
        int j = s.size() - 1;

        while (i<j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
