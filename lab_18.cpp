#include <bits/stdc++.h>
using namespace std;

// Function to check if operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// Precedence
int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

// Convert simple expression to postfix
string exprToPostfix(string expr) {
    stack<char> st;
    string postfix = "";

    for(char c : expr) {
        if(isalnum(c)) postfix += c;
        else if(c=='(') st.push(c);
        else if(c==')') {
            while(!st.empty() && st.top()!='(') { postfix += st.top(); st.pop(); }
            if(!st.empty()) st.pop();
        }
        else if(isOperator(c)) {
            while(!st.empty() && precedence(st.top())>=precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) { postfix += st.top(); st.pop(); }
    return postfix;
}

// Convert if-then-else statement to postfix
string ifStatementToPostfix(vector<string> tokens) {
    stack<string> st; // To track branches
    string result = "";

    for(string tok : tokens) {
        if(tok=="if") st.push("if");
        else if(tok=="then") continue;
        else if(tok=="else") result += "? ";
        else { // expression / operand
            result += exprToPostfix(tok) /**+ " "*/;
        }
    }

    // Add final ? for last branch
    if(!st.empty()) result += "?";

    return result;
}

int main() {
    cout << "Enter statement tokens separated by space:\n";
    cout << "Example: if a then if c-d then a+c else a*c else a+b\n";

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> tokens;
    string tok;
    while(ss >> tok) tokens.push_back(tok);

    string postfix = ifStatementToPostfix(tokens);
    cout << "Postfix / Intermediate Code: " << postfix << endl;

    return 0;
}
