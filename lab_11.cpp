/**
Grammer:    E → E+E
            E → E*E
            E → (E)
            E → id

Input:      id+id*id
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    input += "$";  // end marker

    string stack = "";
    int i = 0;

    cout << "\nStack\tInput\tAction\n";

    while(i < input.size()) {

        // SHIFT
        stack += input[i];
        cout << stack << "\t" << input.substr(i+1) << "\tShift\n";
        i++;

        // REDUCE
        while(true) {
            // id → E
            if(stack.size() >= 2 && stack.substr(stack.size()-2) == "id") {
                stack.replace(stack.size()-2, 2, "E");
                cout << stack << "\t" << input.substr(i) << "\tReduce id→E\n";
            }
            // E+E → E
            else if(stack.size() >= 3 && stack.substr(stack.size()-3) == "E+E") {
                stack.replace(stack.size()-3, 3, "E");
                cout << stack << "\t" << input.substr(i) << "\tReduce E+E→E\n";
            }
            // E*E → E
            else if(stack.size() >= 3 && stack.substr(stack.size()-3) == "E*E") {
                stack.replace(stack.size()-3, 3, "E");
                cout << stack << "\t" << input.substr(i) << "\tReduce E*E→E\n";
            }
            // (E) → E
            else if(stack.size() >= 3 && stack.substr(stack.size()-3) == "(E)") {
                stack.replace(stack.size()-3, 3, "E");
                cout << stack << "\t" << input.substr(i) << "\tReduce (E)→E\n";
            }
            else break;
        }
    }

    // Final check
    if(stack == "E$")
        cout << "\nAccepted\n";
    else
        cout << "\nRejected\n";

    return 0;
}
