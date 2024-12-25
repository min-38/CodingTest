#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxScore = -1;

// 어피치와 라이언의 점수 차이 계산
int calcScoreDiff(const vector<int> &apeach) {
    int scoreApeach = 0, scoreLion = 0;

    for(int i = 0; i < 11; i++) {
        if(apeach[i] == 0 && ryan[i] == 0)
            continue;
        if(apeach[i] >= ryan[i])
            scoreApeach += 10 - i;
        else
            scoreLion += 10 - i;
    }

    return scoreLion - scoreApeach;
}

void dfs(const vector<int> apeach, int score, int arrow) {
    if(score == -1 || arrow == 0) {
        ryan[10] = arrow;
        int scoreDiff = calcScoreDiff(apeach);
        // 현재 구한 점수 차가 기존 최대 점수 차보다 더 크고, 라이언의 점수가 더 높으면 갱신
        if(scoreDiff > 0 && maxScore < scoreDiff) {
            maxScore = scoreDiff;
            answer = ryan;
        }
        ryan[10] = 0;
        return;
    }

    // 여러 어피치가 쏠 화실이 남은 경우
    if(arrow > apeach[score]) {
        ryan[score] = apeach[score] + 1;
        dfs(apeach, score - 1, arrow - apeach[score] - 1);
        ryan[score] = 0;
    }

    // 어피치가 화살을 사용하지 않는 경우
    dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
    // 10점 과녁부터 모든 조합을 확인
    dfs(info, 10, n);

    if(maxScore == -1)
        answer.push_back(-1);

    return answer;
}