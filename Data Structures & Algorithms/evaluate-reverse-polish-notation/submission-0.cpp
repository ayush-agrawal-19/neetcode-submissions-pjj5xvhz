class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        
        stack<string> eval;
        
        for (string c : tokens) {
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                cout << "int pushed: " << c << endl;
                eval.push(c);
            }
            else if (c == "+") {
                cout << "calculation sum: " << endl;
                cout << "int2: " << eval.top() << endl;
                int sum = stoi(eval.top());
                eval.pop();
                cout << "int1: " << eval.top() << endl;
                sum += stoi(eval.top());
                eval.pop();
                eval.push(to_string(sum));
            }
            else if (c == "-") {
                cout << "calculation difference: " << endl;
                cout << "int2: " << eval.top() << endl;
                int difference = - stoi(eval.top());
                eval.pop();
                cout << "int1: " << eval.top() << endl;
                difference += stoi(eval.top());
                eval.pop();
                eval.push(to_string(difference));
            }
            else if (c == "*") {
                cout << "calculation product: " << endl;
                cout << "int2: " << eval.top() << endl;
                int product = stoi(eval.top());
                eval.pop();
                cout << "int1: " << eval.top() << endl;
                product *= stoi(eval.top());
                eval.pop();
                eval.push(to_string(product));
            }
            else if (c == "/") {
                cout << "calculation quotient: " << endl;
                cout << "int2: " << eval.top() << endl;
                int quotient = stoi(eval.top());
                eval.pop();
                cout << "int1: " << eval.top() << endl;
                quotient = stoi(eval.top()) / quotient;
                eval.pop();
                eval.push(to_string(quotient));
            }
        }

        return stoi(eval.top());
    }
};
