#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct State
{
    int x, y;
    string numbers;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 5;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    unordered_set<string> us;

    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            stack<State> s;
            s.push({i, j, ""});

            while (!s.empty())
            {
                auto t = s.top();
                s.pop();

                int x = t.x;
                int y = t.y;
                string numbers = t.numbers;

                if (numbers.length() == 6)
                {
                    if (us.find(numbers) == us.end())
                    {
                        us.insert(numbers);
                        result++;
                    }
                    continue;
                }

                for (int i = 0; i < 4; i++)
                {
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if (newX >= 0 && newX < N && newY >= 0 && newY < N)
                        s.push({newX, newY, numbers + to_string(board[newY][newX])});
                }
            }
        }

    cout << result << endl;

    return 0;
}