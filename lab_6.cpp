#include <bits/stdc++.h>
using namespace std;

// Character Variable
bool isCharVar(string s) {
    if(s.substr(0, 3) != "ch_") return false;

    if(s.size() <= 3) return false;

    for(int i = 3; i < s.size(); i++) {
        if(!isalnum(s[i]))
            return false;
    }
    return true;
}

// Binary Variable
bool isBinVar(string s) {
    if(s.substr(0, 3) != "bn_") return false;

    if(s.size() <= 3) return false;

    for(int i = 3; i < s.size(); i++) {
        if(!isalnum(s[i]))
            return false;
    }
    return true;
}

// Binary Number
bool isBinaryNum(string s) {
    if(s[0] != '0') return false;

    for(char c : s) {
        if(c != '0' && c != '1')
            return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    if(isCharVar(str))
        cout << "Character Variable" << endl;
    else if(isBinVar(str))
        cout << "Binary Variable" << endl;
    else if(isBinaryNum(str))
        cout << "Binary Number" << endl;
    else
        cout << "Invalid Input" << endl;

    return 0;
}
