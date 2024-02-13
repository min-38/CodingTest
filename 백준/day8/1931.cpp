#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector< pair<int, int> > v;

    for(int i = 0; i < N; i++) {
        int start, end;
        cin >> end >> start;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end());

    int time = v[0].first;
    int result = 1;
    for (int i = 1; i <= N; i++) {
        if (v[i].second >= time) {
            result++;
            time = v[i].first;
        }
    }
    cout << result << endl;
    return 0;
}