#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(long long n)
{
    if (n < 2)
        return false;
    
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    
    while (n > 0)
    {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    string value = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            if (value != "" && is_prime(stoll(value)))
                answer++;
            value = "";
            continue;
        }
        value += s[i];
    }
    
    if (value != "" && is_prime(stoll(value)))
        answer++;

    return answer;
}
