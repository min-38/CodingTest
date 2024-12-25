#include <string>
#include <vector>

using namespace std;

void MakeSnail(vector<int>& answer, int level, int start_cursor, int value, int hop, int depth)
{
    if(level < 1)
        return;

    int cursor = start_cursor; // 현재 위치
    // top
    answer[cursor] = value++;

    // left
    for(int i = 1; i < level; i++) {
        cursor += i + hop;
        answer[cursor] = value++;
    }
    
    // bottom
    for(int i = 0; i < level - 1; i++) {
        cursor += 1;
        answer[cursor] = value++;
    }
    
    // right
    for(int i = level; i > 2; i--) {
        cursor -= i + hop;
        answer[cursor] = value++;
    }
    
    hop += 2;
    
    start_cursor += 4 * depth++;

    MakeSnail(answer, level - 3, start_cursor, value, hop, depth);
}

vector<int> solution(int n)
{
    vector<int> answer;
    answer.resize((n * (n + 1)) / 2);

    MakeSnail(answer, n, 0, 1, 0, 1);
    
    return answer;
}