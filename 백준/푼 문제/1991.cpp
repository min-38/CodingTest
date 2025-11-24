#include <iostream>
using namespace std;

struct Node {
    char left;
    char right;
};

Node tree[26]; // 알파벳 개수가 26개

void preorder(char node) {
    if (node == '.') return;

    cout << node;
    preorder(tree[node - 'A'].left);
    preorder(tree[node - 'A'].right);
}

void inorder(char node) {
    if (node == '.') return;

    inorder(tree[node - 'A'].left);
    cout << node;
    inorder(tree[node - 'A'].right);
}

void postorder(char node) {
    if (node == '.') return;

    postorder(tree[node - 'A'].left);
    postorder(tree[node - 'A'].right);
    cout << node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        int idx = root - 'A'; 

        tree[idx].left = left;
        tree[idx].right = right;
    }

    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
    cout << '\n';

    return 0;
}
