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

// Check operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// Build tree from postfix
Node* buildTree(string postfix) {
    stack<Node*> st;

    for(char c : postfix) {
        if(isalnum(c)) {
            st.push(new Node(c));
        }
        else if(isOperator(c)) {
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

// Inorder traversal (to verify)
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    string postfix = "abc*+";

    Node* root = buildTree(postfix);

    cout << "Inorder Traversal of Syntax Tree:\n";
    inorder(root);

    return 0;
}
