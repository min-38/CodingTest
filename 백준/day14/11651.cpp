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
        m[y].push_back(x);
    }

    for(auto element : m){
        sort(element.second.begin(), element.second.end());
        for(int i = 0; i < element.second.size(); i++)
            cout << element.second[i] << " " << element.first << "\n";
    }

    return 0;
}