#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<int> rq1, rq2;
    long long total = 0;
    long long q1sum = 0, q2sum = 0;

    int size = queue1.size();
    
    for (int i = 0; i < size; i++) {
        q1sum += queue1[i];
        q2sum += queue2[i];
        rq1.push(queue1[i]);
        rq2.push(queue2[i]);
    }
    total = q1sum + q2sum;

    int value = 0;
    while (q1sum != q2sum) {
        if (answer > size * 2 + 1) return -1;

        if (q1sum > q2sum) {
            value = rq1.front();
            rq2.push(value);
            q2sum += value;
            q1sum -= value;
            rq1.pop();
        } else {
            value = rq2.front();
            rq1.push(value);
            q1sum += value;
            q2sum -= value;
            rq2.pop();
        }
        answer++;
    }

    return answer;
}