#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

    int box_cnt = cards.size();
    int i_opened = 0;
    vector<bool> v_opened(box_cnt, false);
    vector<int> group;

    while(i_opened < box_cnt) {
        int member = 0;
        int index;
        for(index = 0; index < box_cnt; index++)
            if(!v_opened[index])
                break;

        while(!v_opened[index]) {
            v_opened[index] = true;
            index = cards[index] - 1;
            i_opened++;
            member++;
        }
        group.push_back(member);
    }

    if(group.size() > 1) {
        sort(group.rbegin(), group.rend());
        answer = group[0] * group[1];
    }

    return answer;
}