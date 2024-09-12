#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string sn = to_string(n);
    
    for(int key = 1; key < sn.length(); key++)
        for(int i = 0; i < key; i++)
            if(sn[i] - '0' < sn[key] - '0') {
                char c = sn[key];
                for(int j = key; j > i; j--)
                    sn[j] = sn[j - 1];
                sn[i] = c;
                break;
            }
    
    return stoll(sn);
}