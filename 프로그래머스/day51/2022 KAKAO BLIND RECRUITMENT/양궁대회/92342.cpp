#include <vector>

using namespace std;

vector<int> answer;
int scoreGap = 0; // 점수 차이

// 점수 카운트
void compareScore(const vector<int> &peach, const vector<int> &rian) {
    int peachScore = 0;
    int rianScore = 0;
    
    for(int i = 0; i < peach.size() - 1; i++)
        if(peach[i] < rian[i])
            rianScore += 10 - i;
        else if(peach[i] > rian[i])
            peachScore += 10 - i;

    if(rianScore - peachScore > scoreGap) {
        scoreGap = rianScore - peachScore;
        answer = rian;
    } else if(scoreGap != 0 && rianScore - peachScore == scoreGap) {
        for(int i = rian.size() - 1; i >= 0; i--)
            if(rian[i] > answer[i]) {
                answer = rian;
                break;
            }
    }
}

void shoot(const int arrows, const vector<int> &peach, int shooted, vector<int> rian) {
    if(arrows == shooted) {
        compareScore(peach, rian);
        return;
    }

    for(int i = 0; i < peach.size(); i++)
        if(rian[i] == 0)
            if(arrows - shooted > peach[i]) {
                rian[i] += peach[i] + 1;
                shoot(arrows, peach, shooted + rian[i], rian);
                rian[i] -= peach[i] + 1;
            }
    
    if(arrows != shooted) {
        rian[rian.size() - 1] += arrows - shooted;
        shoot(arrows, peach, arrows, rian);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> rian(info.size(), 0);
    shoot(n, info, 0, rian);

    if(answer.size() == 0)
        answer.push_back(-1);

    return answer;
}