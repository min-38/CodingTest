#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int c1idx = 0, c2idx = 0, gidx = 0; // cards1 인덱스, cards2 인덱스, goal 인덱스

    bool matched = true;
    while(matched && gidx < goal.size()) {
        if(cards1[c1idx] == goal[gidx])
            c1idx++;
        else
            if(cards2[c2idx] == goal[gidx])
                c2idx++;
            else
                matched = false;
        gidx++;
    }

    return matched ? "Yes" : "No";
}