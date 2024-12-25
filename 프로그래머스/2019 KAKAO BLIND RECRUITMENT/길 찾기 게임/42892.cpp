#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int id, x, y;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

// 이전 트리 정의
class BinaryTree {
private:
    Node* root = nullptr;
    // 노드 좌표를 기준으로 정렬할 때 기준이 되는 함수
    static bool compareNodes(Node* a, Node* b) {
        if(a->y != b->y)
            return a->y > b->y;
        return a->x < b->x;
    }

    // 새 노드를 추가하는 함수
    Node* addNode(Node* current, Node* newNode) {
        if(current == nullptr)
            return newNode;
        // 추가하려는 노드의 좌표를 기준으로 현재 노드의 좌, 우 여부 판단 후 추가
        if(newNode->x < current->x)
            current->left = addNode(current->left, newNode);
        else
            current->right = addNode(current->right, newNode);
        
        return current;
    }

    // 전위 순회를 진행하며 경로를 저장하는 함수
    void preOrder(Node* node, vector<int>& traversal) {
        if(node == nullptr)
            return;
        traversal.push_back(node->id);
        preOrder(node->left, traversal);
        preOrder(node->right, traversal);
    }

    void postOrder(Node* node, vector<int>& traversal) {
        if(node == nullptr)
            return;
        postOrder(node->left, traversal);
        postOrder(node->right, traversal);
        traversal.push_back(node->id);
    }
public:
    BinaryTree() : root(nullptr) {}

    // nodeinfo를 기준으로 이진 트리를 구축하는 함수
    void buildTree(const vector<vector<int>>& nodeInfo) {
        vector<Node *> nodes;
        // 각 노드의 (인덱스, x좌표, y좌표) 정보를 nodes에 저장
        for(int i = 0; i < nodeInfo.size(); ++i)
            nodes.push_back(new Node(i + 1, nodeInfo[i][0], nodeInfo[i][1]));
        
        // 이진 트리를 구축하기 위해 노드를 정렬
        sort(nodes.begin(), nodes.end(), compareNodes);
        // 이진 트리 구축
        for(Node* node: nodes)
            root = addNode(root, node);
    }

    // 전위 순회 후 경로를 반환하는 함수
    vector<int> getPreOrderTraversal() {
        vector<int> traversal;
        preOrder(root, traversal);

        return traversal;
    }

    // 후위 순회 후 경로를 반환하는 함수
    vector<int> getPostOrderTraversal() {
        vector<int> traversal;
        postOrder(root, traversal);

        return traversal;
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    BinaryTree tree;

    // 이진 트리를 구축하고 순회 결과를 반환
    tree.buildTree(nodeinfo);
    vector<int> preOrder = tree.getPreOrderTraversal();
    vector<int> postOrder = tree.getPostOrderTraversal();
    
    return {preOrder, postOrder};
}