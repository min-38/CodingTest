#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    unordered_map<string, int> map;
    vector<string> result;

    cin >> N >> M;

    string s = "";
    for (int i = 0; i < N; i++) {
        cin >> s;
        map[s]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> s;

        if(map[s] > 0)
            result.push_back(s);
    }

    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(string s : result)
        cout << s << endl;

    return 0;
}