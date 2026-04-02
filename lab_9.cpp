#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int i = 0, n = s.size();

    // Step 1: count leading 0s (n >= 1)
    int count0_before = 0;
    while(i < n && s[i] == '0') {
        count0_before++;
        i++;
    }

    if(count0_before < 1) return false;

    // Step 2: exactly one '1'
    if(i >= n || s[i] != '1') return false;
    i++;

    // Step 3: count trailing 0s (m >= 1)
    int count0_after = 0;
    while(i < n && s[i] == '0') {
        count0_after++;
        i++;
    }

    if(count0_after < 1) return false;

    // Step 4: no extra characters
    if(i != n) return false;

    return true;
}

int main() {
    string str;
    cin >> str;

    /**
    regex pattern("0+10+");

    if(regex_match(s, pattern))
        cout << "Accepted";
    else
        cout << "Rejected";
    */

    if(isValid(str))
        cout << "Accepted";
    else
        cout << "Rejected";

    return 0;
}
