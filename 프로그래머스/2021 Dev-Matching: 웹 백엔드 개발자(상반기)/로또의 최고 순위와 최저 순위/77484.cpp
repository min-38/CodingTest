#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getRank(int same_number_cnt) {
    if (same_number_cnt >= 6) {
        return 1;
    } else if (same_number_cnt == 5) {
        return 2;
    } else if (same_number_cnt == 4) {
        return 3;
    } else if (same_number_cnt == 3) {
        return 4;
    } else if (same_number_cnt == 2) {
        return 5;
    }
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 6);

    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    int same_number_cnt = 0;
    int zero_cnt = 0;
    int idx1 = 0, idx2 = 0;
    while (idx1 < lottos.size() && idx2 < win_nums.size()) {
        if (lottos[idx1] == win_nums[idx2]) {
            same_number_cnt++;
            idx1++, idx2++;
        } else if(lottos[idx1] < win_nums[idx2]) {
            if (lottos[idx1] == 0) zero_cnt++;
            idx1++;
        } else {
            idx2++;
        }
    }
    
    answer[0] = getRank(same_number_cnt + zero_cnt);
    answer[1] = getRank(same_number_cnt);

    return answer;
}