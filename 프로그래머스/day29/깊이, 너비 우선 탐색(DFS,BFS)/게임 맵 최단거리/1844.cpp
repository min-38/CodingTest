#include<vector>
#include<queue>
using namespace std;

struct Node {
    int x;
    int y;
    int length;
};

Node makeNewNode(Node& node, int px, int py) {
    Node newNode = node;
    newNode.x += px;
    newNode.y += py;
    newNode.length++;
    return newNode;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int MaxX = maps[0].size();
    int MaxY = maps.size();

    queue<Node> pq;
    Node node;
    node.x = 0;
    node.y = 0;
    node.length = 1;
    pq.push(node);

    vector<vector<bool>> visited(MaxY, vector<bool>(MaxX, false));
    visited[0][0] = true;

    while(!pq.empty()) {
        Node node = pq.front();
        pq.pop();
        
        if(node.x == MaxX - 1 && node.y == MaxY - 1)
            if(answer == -1 || answer <= node.length) {
                answer = node.length;
                continue;
            }

        // 하
        if(node.y + 1 < MaxY && !visited[node.y + 1][node.x]) {
            visited[node.y + 1][node.x] = true;
            if(maps[node.y + 1][node.x] == 1)
                pq.push(makeNewNode(node, 0, 1));
        }

        // 좌
        if(node.x + 1 < MaxX && !visited[node.y][node.x + 1]) {
            visited[node.y][node.x + 1] = true;
            if(maps[node.y][node.x + 1] == 1)
                pq.push(makeNewNode(node, 1, 0));
        }

         // 상
        if(node.y - 1 >= 0 && !visited[node.y - 1][node.x]) {
            visited[node.y - 1][node.x] = true;
            if(maps[node.y - 1][node.x] == 1)
                pq.push(makeNewNode(node, 0, -1));
        }

        // 좌
        if(node.x - 1 >= 0 && !visited[node.y][node.x - 1]) {
            visited[node.y][node.x - 1] = true;
            if(maps[node.y][node.x - 1] == 1)
                pq.push(makeNewNode(node, -1, 0));
        }
    }

    return answer;
}