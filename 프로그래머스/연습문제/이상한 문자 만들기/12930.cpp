#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    int idx = 0;

    for (char& c : s) {
        if (c == ' ') {
            idx = 0;
            continue;
        }

        c = (idx % 2 == 0) ? toupper(c) : tolower(c);
        idx++;
    }

    return s;
}
