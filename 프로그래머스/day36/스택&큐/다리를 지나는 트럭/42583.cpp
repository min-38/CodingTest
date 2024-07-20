#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> q; // 트럭 큐
    int arrived = 0; // 도착한 트럭 배열
    int cur_weight = 0; // 현재 다리를 지나는 트럭 무게
    int idx = 0; // 출발할 트럭 idx

    while(arrived < truck_weights.size()) {
        ++answer; // 초 늘어남

        while(!q.empty()) {
            if(answer - q.front() < bridge_length)
                break;
            q.pop();
            cur_weight -= truck_weights[arrived++];
        }

        if(q.size() < bridge_length && idx < truck_weights.size())
            if(cur_weight + truck_weights[idx] <= weight) {
                q.push(answer);
                cur_weight += truck_weights[idx];
                idx++;
            }
    }

    return answer;
}