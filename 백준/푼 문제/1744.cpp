#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  // 수열의 크기
    cin >> N;
    
    priority_queue<int, vector<int>> positive_pq;                 // 양수 우선수위 큐
    priority_queue<int, vector<int>, greater<int>> negative_pq;   // 음수 우선수위 큐
    int one_cnt = 0, zero_cnt = 0;                                // 1 개수, 0 개수

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
            zero_cnt++;
        else if (num == 1)
            one_cnt++;
        else if (num > 1)
            positive_pq.push(num);
        else if (num < 0)
            negative_pq.push(num);
    }

    int result = 0;

    while (negative_pq.size() > 1)
    {
        int a = negative_pq.top(); negative_pq.pop();
        int b = negative_pq.top(); negative_pq.pop();

        result += a * b;
    }

    if (!negative_pq.empty())
        if (zero_cnt == 0)
        {
            result += negative_pq.top();
            negative_pq.pop();
        }
        else
        {
            --zero_cnt;
        }


    while (positive_pq.size() > 1)
    {
        int a = positive_pq.top(); positive_pq.pop();
        int b = positive_pq.top(); positive_pq.pop();

        result += a * b;
    }

    if (!positive_pq.empty())
    {
        result += positive_pq.top();
        positive_pq.pop();
    }
    
    result += one_cnt;

    cout << result << "\n";

    return 0;
}