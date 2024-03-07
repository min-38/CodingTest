#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> pq;

    for(int priority : priorities) {
        pq.push(priority);
    }

    int count = 1;
    int index = 0;
    while(!pq.empty()) {
        int top = pq.top();

        int start_index = index++ % priorities.size();
        if(priorities[start_index] == top) {
            if(start_index == location) {
                answer = count;
                break;
            }
            pq.pop();
            count++;
        }
    }

    return answer;
}