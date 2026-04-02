#include <bits/stdc++.h>
using namespace std;

// Float Variable
bool isFloatVar(string s) {
    char ch = s[0];

    if(!((ch >= 'a' && ch <= 'h') || (ch >= 'A' && ch <= 'H') ||
         (ch >= 'o' && ch <= 'z') || (ch >= 'O' && ch <= 'Z')))
        return false;

    for(int i = 1; i < s.size(); i++) {
        if(!isalnum(s[i]))
            return false;
    }
    return true;
}

// Float Number (2 decimal digits)
bool isFloatNum(string s) {
    int dot = -1;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') dot = i;
    }

    if(dot == -1) return false;

    string left = s.substr(0, dot);
    string right = s.substr(dot+1);

    if(right.size() != 2) return false;

    if(left == "0") {
        // OK
    } else {
        if(left[0] == '0') return false;
        for(char c : left)
            if(!isdigit(c)) return false;
    }

    for(char c : right)
        if(!isdigit(c)) return false;

    return true;
}

// Double Number (3+ decimal digits)
bool isDoubleNum(string s) {
    int dot = -1;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') dot = i;
    }

    if(dot == -1) return false;

    string left = s.substr(0, dot);
    string right = s.substr(dot+1);

    if(right.size() < 3) return false;

    if(left == "0") {
        // OK
    } else {
        if(left[0] == '0') return false;
        for(char c : left)
            if(!isdigit(c)) return false;
    }

    for(char c : right)
        if(!isdigit(c)) return false;

    return true;
}

int main() {
    string str;
    cin >> str;

    if(isFloatVar(str))
        cout << "Float Variable" << endl;
    else if(isFloatNum(str))
        cout << "Float Number" << endl;
    else if(isDoubleNum(str))
        cout << "Double Number" << endl;
    else
        cout << "Invalid Input" << endl;

    return 0;
}
