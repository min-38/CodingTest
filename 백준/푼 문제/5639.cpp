#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

void insert(Node*& root, int v)
{
    if (!root)
    {
        root = new Node({v});
        return;
    }

    if (v < root->value)
        insert(root->left, v);
    else 
        insert(root->right, v);
}

void postorder(Node*& node)
{
    if (node->left)
        postorder(node->left);

    if (node->right)
        postorder(node->right);

    cout << node->value << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = nullptr;

    int num;
    while (cin >> num)
        insert(root, num);

    postorder(root);

    return 0;
}
