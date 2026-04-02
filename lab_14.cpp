/**
Grammar: E → E+T | T
         T → T*F | F
         F → (E) | id

First:  FIRST(E) = { id, ( }
        FIRST(T) = { id, ( }
        FIRST(F) = { id, ( }

Follow: FOLLOW(E) = { $, ) }
        FOLLOW(T) = { +, $, ) }
        FOLLOW(F) = { *, +, $, ) }
*/
#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSet, followSet;

// FIRST function
set<char> FIRST(char c) {
    if(!isupper(c)) return {c};

    if(!firstSet[c].empty()) return firstSet[c];

    for(string prod : grammar[c]) {
        for(int i = 0; i < prod.size(); i++) {
            set<char> temp = FIRST(prod[i]);

            for(char t : temp) {
                if(t != 'e') firstSet[c].insert(t);
            }

            if(temp.find('e') == temp.end())
                break;

            if(i == prod.size()-1)
                firstSet[c].insert('e');
        }
    }
    return firstSet[c];
}

// FOLLOW function
void FOLLOW(char c) {
    if(c == 'S') followSet[c].insert('$');

    for(auto &rule : grammar) {
        char lhs = rule.first;

        for(string prod : rule.second) {
            for(int i = 0; i < prod.size(); i++) {
                if(prod[i] == c) {
                    if(i+1 < prod.size()) {
                        set<char> temp = FIRST(prod[i+1]);
                        for(char t : temp) {
                            if(t != 'e') followSet[c].insert(t);
                        }
                    } else {
                        if(c != lhs)
                            FOLLOW(lhs);
                        for(char t : followSet[lhs])
                            followSet[c].insert(t);
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        char lhs;
        string rhs;
        cin >> lhs >> rhs;
        grammar[lhs].push_back(rhs);
    }

    // Compute FIRST
    for(auto g : grammar)
        FIRST(g.first);

    // Compute FOLLOW
    for(auto g : grammar)
        FOLLOW(g.first);

    // Output FIRST
    cout << "\nFIRST sets:\n";
    for(auto f : firstSet) {
        cout << f.first << " = { ";
        for(char c : f.second) cout << c << " ";
        cout << "}\n";
    }

    // Output FOLLOW
    cout << "\nFOLLOW sets:\n";
    for(auto f : followSet) {
        cout << f.first << " = { ";
        for(char c : f.second) cout << c << " ";
        cout << "}\n";
    }

    return 0;
}
