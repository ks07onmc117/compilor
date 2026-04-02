#include <bits/stdc++.h>
using namespace std;

// Check Keyword
bool isKeyword(string s) {
    string keywords[] = {"int","float","double","char","if","else","for","while","do","return"};
    for(string k : keywords)
        if(s == k) return true;
    return false;
}

// Check Operator
bool isOperator(string s) {
    string ops[] = {"+","-","*","/","=","==","<",">","<=",">=","!="};
    for(string op : ops)
        if(s == op) return true;
    return false;
}

// Check Constant (Integer or Float)
bool isConstant(string s) {
    bool hasDot = false;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') {
            if(hasDot) return false;
            hasDot = true;
        }
        else if(!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

// Check Identifier
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
        cout << "Operator";
    else if(isConstant(str))
        cout << "Constant";
    else if(isIdentifier(str))
        cout << "Identifier";
    else
        cout << "Invalid";

    return 0;
}
