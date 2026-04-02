#include <bits/stdc++.h>
using namespace std;

// Grammar storage
map<string, vector<string>> grammar;

// FIRST and FOLLOW sets
map<string, set<string>> FIRST, FOLLOW;

// LL(1) Parsing table
map<pair<string,string>, string> table;

// Start symbol
string startSymbol = "E";

// Check if terminal
bool isTerminal(string s) {
    return !(s[0] >= 'A' && s[0] <= 'Z'); // Capital letters = Non-terminals
}

// Compute FIRST of a string
set<string> firstOfString(string str) {
    set<string> result;
    if(str == "") return {"#"}; // ε

    for(int i = 0; i < str.size(); i++) {
        string sym(1, str[i]);
        if(!isupper(sym[0])) {  // Terminal
            result.insert(sym);
            break;
        }

        for(auto x : FIRST[sym]) {
            if(x != "#") result.insert(x);
        }

        if(FIRST[sym].count("#") == 0) break; // ε not present, stop

        if(i == str.size()-1) result.insert("#"); // All ε → add #
    }

    return result;
}

// Compute FIRST sets iteratively
void computeFIRST() {
    bool changed = true;

    while(changed) {
        changed = false;
        for(auto &g : grammar) {
            string A = g.first;
            for(string prod : g.second) {
                set<string> temp = firstOfString(prod);
                for(auto t : temp) {
                    if(!FIRST[A].count(t)) {
                        FIRST[A].insert(t);
                        changed = true;
                    }
                }
            }
        }
    }
}

// Compute FOLLOW sets iteratively
void computeFOLLOW() {
    FOLLOW[startSymbol].insert("$");

    bool changed = true;

    while(changed) {
        changed = false;
        for(auto &g : grammar) {
            string A = g.first;
            for(string prod : g.second) {
                for(int i = 0; i < prod.size(); i++) {
                    string B(1, prod[i]);
                    if(isupper(B[0])) {
                        string beta = prod.substr(i+1);
                        set<string> firstBeta = firstOfString(beta);

                        for(auto x : firstBeta) {
                            if(x != "#") {
                                if(!FOLLOW[B].count(x)) {
                                    FOLLOW[B].insert(x);
                                    changed = true;
                                }
                            }
                        }

                        if(firstBeta.count("#") || beta == "") {
                            for(auto x : FOLLOW[A]) {
                                if(!FOLLOW[B].count(x)) {
                                    FOLLOW[B].insert(x);
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Build LL(1) parsing table
void buildTable() {
    for(auto &g : grammar) {
        string A = g.first;
        for(string prod : g.second) {
            set<string> firstAlpha = firstOfString(prod);

            for(auto t : firstAlpha) {
                if(t != "#") table[{A, t}] = prod;
            }

            if(firstAlpha.count("#")) {
                for(auto t : FOLLOW[A]) {
                    table[{A, t}] = prod;
                }
            }
        }
    }
}

int main() {
    // Grammar: Example LL(1) grammar
    grammar["E"]  = {"TE'"};
    grammar["E'"] = {"+TE'", "#"};
    grammar["T"]  = {"FT'"};
    grammar["T'"] = {"*FT'", "#"};
    grammar["F"]  = {"(E)", "i"}; // 'i' = id

    // Compute FIRST, FOLLOW
    computeFIRST();
    computeFOLLOW();

    // Build Parsing Table
    buildTable();

    // Print FIRST sets
    cout << "FIRST sets:\n";
    for(auto &f : FIRST) {
        cout << f.first << " = { ";
        for(auto x : f.second) cout << x << " ";
        cout << "}\n";
    }

    // Print FOLLOW sets
    cout << "\nFOLLOW sets:\n";
    for(auto &f : FOLLOW) {
        cout << f.first << " = { ";
        for(auto x : f.second) cout << x << " ";
        cout << "}\n";
    }

    // Print LL(1) Table
    cout << "\nLL(1) Parsing Table:\n";
    for(auto &entry : table) {
        cout << "M[" << entry.first.first << ", "
             << entry.first.second << "] = "
             << entry.first.first << " -> " << entry.second << endl;
    }

    return 0;
}
