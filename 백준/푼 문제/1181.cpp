#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    map<int, set<string>> m;
    int N;
    string s = "";

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;
        m[s.length()].insert(s);
    }

    for(auto element : m)
        for (auto it = element.second.begin(); it != element.second.end(); ++it)
            cout << *it << "\n";

    return 0;
}