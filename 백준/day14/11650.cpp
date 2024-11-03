#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    map<int, vector<int>> m;

    int N;
    cin >> N;

    int x, y;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        m[x].push_back(y);
    }

    for(auto x : m){
        sort(x.second.begin(), x.second.end());
        for(int i = 0; i < x.second.size(); i++)
            cout << x.first << " " << x.second[i] << "\n";
    }

    return 0;
}