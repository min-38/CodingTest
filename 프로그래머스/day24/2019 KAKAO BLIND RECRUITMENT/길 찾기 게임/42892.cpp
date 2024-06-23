#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int num;
    int x;
    int y;
    Node* left;
    Node* right;
};

void ConnectNodes(Node* pn, Node* cn);
void Preorder(vector<int>* v, Node* n);
void Postorder(vector<int>* v, Node* n);

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node*> v;
    for(int i = 0; i < nodeinfo.size(); i++) {
        Node* n = new Node();
        n->num = i + 1;
        n->x = nodeinfo[i][0];
        n->y = nodeinfo[i][1];
        n->left = NULL;
        n->right = NULL;
        v.push_back(n);
    }

    sort(v.begin(), v.end(), [](const Node* a, const Node* b) {
        if (a->y == b->y)
            return a->x < b->x;
        return a->y > b->y;
    });
    
    Node* rn = v[0];
    
    for(int i = 1; i < v.size(); i++)
        ConnectNodes(rn, v[i]);
    
    vector<vector<int>> answer;
    vector<int> v0;
    Preorder(&v0, rn);
    answer.push_back(v0);
    
    vector<int> v1;
    Postorder(&v1, rn);
    answer.push_back(v1);
    
    return answer;
}

void ConnectNodes(Node* pn, Node* cn) {
    if(cn->y < pn->y)
        if(cn->x < pn->x)
            if(pn->left == NULL)
                pn->left = cn;
            else
                ConnectNodes(pn->left, cn);
        else
            if(pn->right == NULL)
                pn->right = cn;
            else
                ConnectNodes(pn->right, cn);
}

void Preorder(vector<int>* v, Node* n) {
    v->push_back(n->num);
    if(n->left != NULL)
        Preorder(v, n->left);
    if(n->right != NULL)
        Preorder(v, n->right);
}

void Postorder(vector<int>* v, Node* n) {
    if(n->left != NULL)
        Postorder(v, n->left);
    if(n->right != NULL)
        Postorder(v, n->right);
    v->push_back(n->num);
}
