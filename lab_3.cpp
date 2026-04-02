#include <bits/stdc++.h>
using namespace std;

int main() {
    string code;
    cin >> code;

    if(code == "CSE-3141")
        cout << "Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory";
    else if(code == "CSE-2142")
        cout << "Another subject info";
    else
        cout << "Invalid Code";

    return 0;
}

/**
 map<string, string> mp;
mp["CSE-3141"] = "Full description";
*/
