#include <bits/stdc++.h>
using namespace std;

// Keyword check
bool isKeyword(string s) {
    string keywords[] = {"int","float","double","char","if","else","for","while","do","return"};
    for(string k : keywords)
        if(s == k) return true;
    return false;
}

// Operator check
bool isOperator(string s) {
    string ops[] = {"+","-","*","/","%"};  // arithmetic operators
    for(string op : ops)
        if(s == op) return true;
    return false;
}

// Integer check
bool isInteger(string s) {
    for(char c : s)
        if(!isdigit(c)) return false;
    return true;
}

// Float check
bool isFloat(string s) {
    int dot = 0;

    for(char c : s) {
        if(c == '.') dot++;
        else if(!isdigit(c)) return false;
    }

    return (dot == 1);
}

// Identifier check
bool isIdentifier(string s) {
    if(!(isalpha(s[0]) || s[0] == '_'))
        return false;

    for(int i = 1; i < s.size(); i++) {
        if(!(isalnum(s[i]) || s[i] == '_'))
            return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    if(isKeyword(str))
        cout << "Keyword";
    else if(isOperator(str))
        cout << "Arithmetic Operator";
    else if(isFloat(str))
        cout << "Float";
    else if(isInteger(str))
        cout << "Integer";
    else if(isIdentifier(str))
        cout << "Identifier";
    else
        cout << "Invalid";

    return 0;
}
