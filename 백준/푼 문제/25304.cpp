#include <iostream>

using namespace std;

int main()
{
    unsigned long long X;
    int N;
    cin >> X;
    cin >> N;

    unsigned long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        unsigned long long a, b;
        cin >> a >> b;

        sum += a * b;
    }

    if (X == sum)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
