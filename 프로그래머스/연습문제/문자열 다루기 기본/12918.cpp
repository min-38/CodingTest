#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int len = s.length();
    if (len != 4 && len != 6) return false;
    
    for (char c : s)
        if (c > 64 && c < 123)
            return false;

    return true;
}
