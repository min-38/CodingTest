#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node { int val, cost; };
struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        if (a.cost != b.cost) return a.cost > b.cost; // cost 작은 게 먼저
        return a.val > b.val;
    }
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<Node, vector<Node>, Cmp> pq;
    pq.push({N, 0});

    vector<int> used(N + 1, INT_MAX);
    used[N] = 0;

    int result = 0;

    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();

        int value = top.val;
        int cost = top.cost;

        if (value == 1) {
            result = cost;
            break;
        }

        int newCost = cost + 1;
        if (value % 3 == 0 && newCost < used[value / 3])
        {
            pq.push({value / 3, newCost});
            used[value / 3] = newCost;

        }
        if (value % 2 == 0 && newCost < used[value / 2])
        {
            pq.push({value / 2, newCost});
            used[value / 2] = newCost;

        }
        if (value - 1 >= 1 && newCost < used[value - 1])
        {
            pq.push({value - 1, newCost});
            used[value - 1] = newCost;

        }
    }

    cout << result << endl;

    return 0;
}