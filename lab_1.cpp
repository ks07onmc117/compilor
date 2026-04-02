#include <bits/stdc++.h>
using namespace std;


int main() {
   // string str = " Md. Tareq Zaman, Part-3, 2011";
    freopen("input.txt", "r", stdin);

    string str;
    getline(cin, str);
    int letters = 0, digits = 0, words = 0, others = 0;

    string letterStr = "", digitStr = "", otherStr = "";

    for(int i = 0; i < str.size(); i++) {

        if(isalpha(str[i])) {
            letters++;
            letterStr += str[i];
        }
        else if(isdigit(str[i])) {
            digits++;
            digitStr += str[i];
        }
        else if(str[i] == ' ') {
            continue;
        }
        else {
            others++;
            otherStr += str[i];
        }
    }

    // Word count
    stringstream ss(str);
    string word;
    while(ss >> word) {
        words++;
    }

    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Words: " << words << endl;
    cout << "Others: " << others << endl;

    cout << "\nSeparated:\n";
    cout << "Letters: " << letterStr << endl;
    cout << "Digits: " << digitStr << endl;
    cout << "Others: " << otherStr << endl;

    return 0;
}
