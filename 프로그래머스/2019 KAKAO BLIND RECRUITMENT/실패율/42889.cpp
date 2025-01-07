#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Stage {
    int num;
    double fail;
};

bool cmp(Stage &s1, Stage &s2) {
    if(s1.fail > s2.fail)
        return false;
    else if(s1.fail == s2.fail)
        if(s1.num < s2.num)
            return false;
    return true;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<Stage> v;
    int user_cnt = stages.size();

    sort(stages.begin(), stages.end());
    
    int curStage = 1;
    int i = 0;
    while(curStage <= N) {
        double nonClearUserCnt = 0;
        double chanllengedUserCnt = user_cnt - i;
        for (i; i <= user_cnt; i++) {
            if (curStage != stages[i])
                break;
            nonClearUserCnt++;
        }

        if (nonClearUserCnt == 0)
            v.push_back({curStage, 0});
        else
            v.push_back({curStage, nonClearUserCnt / chanllengedUserCnt});
        curStage++;
    }

    sort(v.rbegin(), v.rend(), cmp);

    for (Stage d : v)
        answer.push_back(d.num);

    return answer;
}
