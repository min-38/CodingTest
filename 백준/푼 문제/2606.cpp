#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N, M; // 컴퓨터 개수, 연결 수
    cin >> N >> M;

    vector<vector<int>> computers(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        computers[a].push_back(b);
        computers[b].push_back(a);
    }

    stack<int> stack;
    stack.push(1);

    int result = 0;
    while (!stack.empty())
    {
        int cur = stack.top();
        stack.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        result++;

        for (int next : computers[cur])
            if (!visited[next])
                stack.push(next);
    }
    cout << result - 1 << endl;
}