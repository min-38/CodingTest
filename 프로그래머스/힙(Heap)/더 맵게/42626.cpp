#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while(pq.size() >= 2 && pq.top() < K) {
        int minScoville = pq.top();
        pq.pop();
        int minScoville2 = pq.top();
        pq.pop();

        pq.push(minScoville + minScoville2 * 2);
        answer++;
    }

    if(pq.top() < K)
        return -1;

    return answer;
}