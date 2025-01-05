#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    map<string, string, greater<string>> m;

    string s = "";
    for (int i = 0; i < N; i++) {
        getline(cin, s);

        int cut = 0;
        for (int j = 0; j < s.length(); j++)
            if(s[j] == ' ') {
                cut = j;
                break;
            }
        
        m[s.substr(0, cut)] = s.substr(cut + 1);
    }

    for (auto e : m)
        if(e.second != "leave")
            cout << e.first << "\n";

    return 0;
}