#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check(string input) {
    stack<char> stk;
    if (input[0] == ')' or input[0] == '}' or input[0] == ']') {
        cout << "Error!" << endl;
        return 0;
    }
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(' or input[i] == '{' or input[i] == '[') {
            stk.push(input[i]);
        }
        else if (input[i] == ')' or input[i] == '}' or input[i] == ']') {
            if (stk.empty()) {
                return 0;
            }
            if (input[i] == ')' and stk.top() == '(') {
                stk.pop();
            }
            else if (input[i] == '}' and stk.top() == '{') {
                stk.pop();
            }
            else if (input[i] == ']' and stk.top() == '[') {
                stk.pop();
            }
            else {
                return 0;
            }
        }
    }

    return stk.empty();
}

int main() {
    string input;

    getline(cin, input);
    if (check(input)) {
        cout << "True";
    }
    else {
        cout << "False";
    }
}