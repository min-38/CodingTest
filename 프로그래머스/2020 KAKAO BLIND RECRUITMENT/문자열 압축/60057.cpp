#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int n = s.length();

    if (n == 1)
        return 1;
    
    int answer = n;

    // unit 단위로 문자열을 순회
    for (int unit = 1; unit <= n / 2; ++unit)
    {
        string compressed = "";

        for (int i = 0; i < n; ) {
            string current_chunk = s.substr(i, unit);
            int count = 1;

            // 현재 문자열(current_chunk)과 몇 번 반복되는지 확인
            int next_pos = i + unit;
            while (next_pos < n && s.substr(next_pos, unit) == current_chunk)
            {
                count++;
                next_pos += unit;
            }

            if (count > 1)
                compressed += to_string(count);
            compressed += current_chunk;

            // 다음 탐색 위치로 이동
            i = next_pos;
        }

        answer = min(answer, (int)compressed.length());
    }

    return answer;
}