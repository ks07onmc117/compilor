#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

int main() {
    string str = "Munmun is the student of Computer Science & Engineering";

    int vowels = 0, consonants = 0;

    set<char> vowelSet, consonantSet;

    // Count vowels and consonants
    for(char ch : str) {
        if(isalpha(ch)) {
            if(isVowel(ch)) {
                vowels++;
                vowelSet.insert(tolower(ch));
            } else {
                consonants++;
                consonantSet.insert(tolower(ch));
            }
        }
    }

    cout << "Vowels Count: " << vowels << endl;
    cout << "Consonants Count: " << consonants << endl;

    cout << "\nVowels present: ";
    for(auto v : vowelSet) cout << v << " ";

    cout << "\nConsonants present: ";
    for(auto c : consonantSet) cout << c << " ";

    // Divide words
    stringstream ss(str);
    string word;

    string vowelWords = "", consonantWords = "";

    while(ss >> word) {
        char first = tolower(word[0]);

        if(isalpha(first)) {
            if(isVowel(first))
                vowelWords += word + " ";
            else
                consonantWords += word + " ";
        }
    }

    cout << "\n\nWords starting with vowel: " << vowelWords << endl;
    cout << "Words starting with consonant: " << consonantWords << endl;

    return 0;
}
