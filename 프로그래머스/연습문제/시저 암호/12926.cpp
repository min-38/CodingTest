#include <string>

using namespace std;

string solution(string s, int n) {
    for (char& c : s)
    {
        if (c == ' ') continue;

        char base = isupper(c) ? 'A' : 'a';
        c = base + (c - base + n) % 26;
    }

    return s;
}
