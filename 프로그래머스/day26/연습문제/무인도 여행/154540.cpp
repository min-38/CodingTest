#include <string>
#include <vector>

using namespace std;

void move(vector<string> maps, int y, int x, int& sum, vector<vector<bool>>& visited)
{
    if(maps[y][x] == 'X' || visited[y][x])
        return;

    visited[y][x] = true;
    sum += maps[y][x] - '0';

    // 상
    if(y > 0)
        move(maps, y - 1, x, sum, visited);
    // 하
    if(y < maps.size() - 1)
        move(maps, y + 1, x, sum, visited);
    // 좌
    if(x > 0)
        move(maps, y, x - 1, sum, visited);
    // 우
    if(x < maps[0].length() - 1)
        move(maps, y, x + 1, sum, visited);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));

    for(int i = 0; i < maps.size(); i++)
        for(int j = 0; j < maps[0].length(); j++)
            if(maps[i][j] != 'X' && !visited[i][j])
            {
                int sum = 0;
                move(maps, i, j, sum, visited);
                printf("sum = %d\n", sum);
                answer.push_back(sum);
            }

    if(answer.empty())
        answer.push_back(-1);

    return answer;
}

int main()
{
    vector<string> v;
    v.push_back("X591X");
    v.push_back("X1X5X");
    v.push_back("X231X");
    v.push_back("1XXX1");

    vector<int> r;
    r = solution(v);

    // for(int i = 0; r.size(); i++) {
    //     printf("wwww %d %d\n", i, r[i]);
    // }

    
    return 0;
}