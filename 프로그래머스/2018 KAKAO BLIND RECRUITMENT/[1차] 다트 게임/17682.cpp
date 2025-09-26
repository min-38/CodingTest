#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> scores;

    int idx = 0;
    string num = "";
    while (idx < dartResult.length())
    {
        char c = dartResult[idx++];

        // 점수 처리
        if (c >= 48 && c <= 59)
        {
            num += c;
            continue;
        }

        if (num != "")
        {
            scores.push_back(stoi(num));
            num = "";
        }

        // 보너스 처리
        int score_size = scores.size() - 1;
        if (c == 'D')
            scores[score_size] = pow(scores[score_size], 2);

        if (c == 'T')
            scores[score_size] = pow(scores[score_size], 3);

        // 옵션 처리
        if (c == '*')
        {
            scores[score_size] = scores[score_size] * 2;
            if (score_size > 0)
                scores[score_size - 1] = scores[score_size - 1] * 2;
        }

        if (c == '#')
            scores[score_size] *= -1;
    }
    
    for (int score : scores)
        answer += score;
        
    return answer;
}
