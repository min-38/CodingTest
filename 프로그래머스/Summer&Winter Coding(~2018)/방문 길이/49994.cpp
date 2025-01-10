#include <string>

using namespace std;

bool visited[11][11][4];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool isNotValid(int x, int y) { return x < 0 || y < 0 || x > 10 || y > 10; };
int opposite_direction(int dir) { return (dir + 2) % 4; };

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    int direct = 0;

    for(char c : dirs) {
        if (c == 'U')
            direct = 0;
        else if (c == 'R')
            direct = 1;
        else if (c == 'D')
            direct = 2;
        else
            direct = 3;
        
        int nx = x + dx[direct];
        int ny = y + dy[direct];
        
        if (isNotValid(nx, ny))
            continue;

        if (visited[y][x][direct] == false) {
            visited[y][x][direct] = true;
            visited[ny][nx][opposite_direction(direct)] = true;
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}