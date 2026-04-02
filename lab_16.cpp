#include <bits/stdc++.h>
using namespace std;

// Grammar
map<string, vector<string>> grammar;
map<pair<string,string>, string> table;
string startSymbol = "E";

// Terminal check
bool isTerminal(string s) {
    return !(s[0] >= 'A' && s[0] <= 'Z');
}

// Function to build LL(1) table (simplified, assume table given)
void buildTable() {
    // Example grammar: same as Exp-15
    grammar["E"]  = {"TE'"};
    grammar["E'"] = {"+TE'", "#"};
    grammar["T"]  = {"FT'"};
    grammar["T'"] = {"*FT'", "#"};
    grammar["F"]  = {"(E)", "i"};

    // Manually filled LL(1) table for simplicity
    table[{"E", "i"}]  = "TE'";
    table[{"E", "("}]  = "TE'";
    table[{"E'", "+"}] = "+TE'";
    table[{"E'", ")"}] = "#";
    table[{"E'", "$"}] = "#";
    table[{"T", "i"}]  = "FT'";
    table[{"T", "("}]  = "FT'";
    table[{"T'", "*"}] = "*FT'";
    table[{"T'", "+"}] = "#";
    table[{"T'", ")"}] = "#";
    table[{"T'", "$"}] = "#";
    table[{"F", "i"}]  = "i";
    table[{"F", "("}]  = "(E)";
}

// Predictive Parser
bool predictiveParser(string input) {
    stack<string> st;
    st.push("$");
    st.push(startSymbol);

    input += "$";
    int ip = 0;

    cout << "Stack\tInput\tAction\n";

    while(!st.empty()) {
        string top = st.top();
        string curr(1, input[ip]);

        // Print stack
        stack<string> temp = st;
        vector<string> stk;
        while(!temp.empty()) { stk.push_back(temp.top()); temp.pop(); }
        reverse(stk.begin(), stk.end());
        for(string s : stk) cout << s;
        cout << "\t" << input.substr(ip) << "\t";

        if(top == curr && top == "$") {
            cout << "ACCEPT\n";
            return true;
        }

        if(top == curr) {
            cout << "Match " << curr << "\n";
            st.pop();
            ip++;
        }
        else if(!isTerminal(top)) {
            auto it = table.find({top, curr});
            if(it != table.end()) {
                cout << top << "->" << it->second << "\n";
                st.pop();
                string prod = it->second;
                if(prod != "#") { // ε
                    for(int i = prod.size()-1; i >= 0; i--) {
                        st.push(string(1, prod[i]));
                    }
                }
            } else {
                cout << "ERROR\n";
                return false;
            }
        } else {
            cout << "ERROR\n";
            return false;
        }
    }

    return false;
}

int main() {
    buildTable();

    string input;
    cout << "Enter input string (terminals i,+,*,(), etc.): ";
    cin >> input;

    if(!predictiveParser(input)) {
        cout << "REJECT\n";
    }

    return 0;
}
