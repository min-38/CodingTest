#include <iostream>
#include <queue>

using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};

struct Node {
    int x;
    int y;
    int moved = 0;
    int apple = 0;
    bool visited[5][5] = { false };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5][5] = { 0 };
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> arr[i][j];
    
    int r, c;
    cin >> r >> c;

    queue<Node> q;
    q.push({c, r});

    while (!q.empty()) {
        Node n = q.front();
        q.pop();

        if(arr[n.y][n.x] == 1)
            n.apple++;
        n.visited[n.y][n.x] = true;

        if(n.apple >= 3) {
            printf("%d\n", n.moved);
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int x = n.x + dx[k];
            int y = n.y + dy[k];

            if (x >= 0 && y >= 0 && x < 5 && y < 5)
                if (arr[y][x] != -1 && !n.visited[y][x]) {
                    Node new_n = n;
                    new_n.x = x;
                    new_n.y = y;
                    new_n.moved++;
                    q.push(new_n);
                }
        }
    }

    printf("%d\n", -1);

    return 0;
}