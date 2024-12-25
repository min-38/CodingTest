#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    for(int work : works)
        pq.push(work);

    while(n-- > 0 && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        top -= 1;
        if(top != 0)
            pq.push(top);
    }

    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();
        answer += top * top;
    }
    return answer;
}