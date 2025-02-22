#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for(int i = 2 ; i <= sqrt(num) ; i++)
        if(num % i == 0)
            return false;

    return true;
}

bool isPalindrome(string str)
{
    string A = str;
    reverse(str.begin(), str.end());
    string B = str;

    if(A == B)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = N; ; i++)
    {
        if (isPrime(i))
            if (isPalindrome(to_string(i)))
            {
                cout << i << "\n";
                break;
            }
    }

    return 0;
}