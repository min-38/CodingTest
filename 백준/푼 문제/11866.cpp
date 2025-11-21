#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> result;
    list<int> li;
    for (int i = 1; i <= N; i++)
        li.push_back(i);

    while(li.size() > 0) {
        for (int i = 1; i < K; i++) {
            li.push_back(li.front());
            li.pop_front();
        }
        result.push_back(li.front());
        li.pop_front();
    }

    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << ">\n";

    return 0;
}