#include <bits/stdc++.h>
using namespace std;

// Check operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// Check valid identifier or number
bool isOperand(char c) {
    return isalnum(c); // letter or digit
}

// Check parentheses balance
bool checkParentheses(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(')
            st.push(c);
        else if(c == ')') {
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

// Main validation function
bool isValid(string s) {
    if(!checkParentheses(s)) return false;

    for(int i = 0; i < s.size(); i++) {

        // Invalid character
        if(!isOperator(s[i]) && !isOperand(s[i]) && s[i] != '(' && s[i] != ')')
            return false;

        // Two operators together → invalid
        if(i > 0 && isOperator(s[i]) && isOperator(s[i-1]))
            return false;

        // Expression cannot start or end with operator
        if(i == 0 && isOperator(s[i])) return false;
        if(i == s.size()-1 && isOperator(s[i])) return false;
    }

    return true;
}

int main() {
    string s;
    cout << "Enter expression: ";
    cin >> s;

    if(isValid(s))
        cout << "VALID";
    else
        cout << "INVALID";

    return 0;
}
