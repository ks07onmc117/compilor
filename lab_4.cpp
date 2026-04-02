#include <bits/stdc++.h>
using namespace std;

// Check Integer Variable
bool isIntVar(string s) {
    if(!( (s[0]>='i' && s[0]<='n') || (s[0]>='I' && s[0]<='N') ))
        return false;

    for(int i = 1; i < s.size(); i++) {
        if(!isalnum(s[i]))
            return false;
    }
    return true;
}

// Check ShortInt
bool isShortInt(string s) {
    if(s[0]=='0') return false;
    if(s.size() >= 1 && s.size() <= 4) {
        for(char c : s) {
            if(!isdigit(c)) return false;
        }
        return true;
    }
    return false;
}

// Check LongInt
bool isLongInt(string s) {
    if(s[0]=='0') return false;
    if(s.size() >= 5) {
        for(char c : s) {
            if(!isdigit(c)) return false;
        }
        return true;
    }
    return false;
}

int main() {
    string str;
    cin >> str;

    if(isIntVar(str))
        cout << "Integer Variable" << endl;
    else if(isShortInt(str))
        cout << "ShortInt Number" << endl;
    else if(isLongInt(str))
        cout << "LongInt Number" << endl;
    else
        cout << "Invalid Input" << endl;

    return 0;
}
