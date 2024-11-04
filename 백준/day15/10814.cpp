#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<int, vector<string>> m;
    int N;
    cin >> N;

    int age = 0;
    string name = "";

    for(int i = 0; i < N; i++) {
        cin >> age >> name;
        m[age].push_back(name);
    }

    for(auto element : m)
        for(string s : element.second)
            cout << element.first << " " << s << "\n";

    return 0;
}