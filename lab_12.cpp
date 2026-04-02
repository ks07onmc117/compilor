#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    char val;
    Node *left, *right;

    Node(char v) {
        val = v;
        left = right = NULL;
    }
};

// Operator check
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// Precedence
int precedence(char c) {
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

// Infix → Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for(char c : s) {

        if(isalnum(c)) {
            result += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else { // operator
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Build Tree from Postfix
Node* buildTree(string postfix) {
    stack<Node*> st;

    for(char c : postfix) {
        if(isalnum(c)) {
            st.push(new Node(c));
        }
        else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            Node* newNode = new Node(c);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }
    return st.top();
}

// Inorder traversal
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    Node* root = buildTree(postfix);

    cout << "Inorder traversal of syntax tree:\n";
    inorder(root);

    return 0;
}
