#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0, y = 0;
    for (char c : s) {
        if (c == 'p' || c == 'P')
            p++;
        
        if (c == 'y' || c == 'Y')
            y++;
    }
    
    if (p == y)
        return true;
    return false;
}