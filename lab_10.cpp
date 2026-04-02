#include <bits/stdc++.h>
using namespace std;

// Sets for grammar rules
set<string> PN = {"Sagor","Selim","Salma","Nipu"};
set<string> P = {"he","she","I","we","you","they"};
set<string> N = {"book","cow","dog","home","grass","rice","mango"};
set<string> V = {"read","eat","take","run","write"};

bool isSUB(string word) {
    return PN.count(word) || P.count(word);
}

bool isPRED(vector<string> words) {
    if(words.size() == 1) {
        return V.count(words[0]);
    }
    else if(words.size() == 2) {
        return V.count(words[0]) && N.count(words[1]);
    }
    return false;
}

int main() {
    string line;
    getline(cin, line);

    // Split sentence
    stringstream ss(line);
    vector<string> words;
    string w;

    while(ss >> w)
        words.push_back(w);

    if(words.size() < 2) {
        cout << "Invalid";
        return 0;
    }

    // First word → SUB
    if(!isSUB(words[0])) {
        cout << "Invalid";
        return 0;
    }

    // Remaining → PRED
    vector<string> pred(words.begin()+1, words.end());

    if(isPRED(pred))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}
