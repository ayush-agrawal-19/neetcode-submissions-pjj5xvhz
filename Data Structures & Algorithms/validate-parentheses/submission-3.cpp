class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;

        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                cout << "bracket pushed: " << s[i] << endl;
                bracket.push(s[i]);
            }
            else if (bracket.empty()) {
                return false;
            }
            else if (s[i] == ')') {
                if (bracket.top() != '(') {
                    return false;
                }
                cout << "bracket top: " << bracket.top() << endl;
                bracket.pop();
            }
            else if (s[i] == ']') {
                if (bracket.top() != '[') {
                    return false;
                }
                cout << "bracket top: " << bracket.top() << endl;
                bracket.pop();
            }
            else if (s[i] == '}') {
                if (bracket.top() != '{') {
                    return false;
                }
                cout << "bracket top: " << bracket.top() << endl;
                bracket.pop();
            }
        }

        if (bracket.empty()) {
            return true;
        }

        return false;
    }
};
