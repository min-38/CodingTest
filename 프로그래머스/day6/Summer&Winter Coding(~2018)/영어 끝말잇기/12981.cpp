#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> usedWords;

    usedWords.insert(words[0]);

    // 두 번째 단어부터 끝까지 반복
    for(int i = 1; i < words.size(); i++) {
        // 단어가 이미 사용되었거나, 끝말잇기 규칙에 맞지 않는 경우
        if(!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back()) {
            // 플레이어 번호와 턴 번호 저장 후 바로 반환
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
    }

    return answer;
}