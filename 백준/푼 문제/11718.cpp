#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << s << endl;
        if (cin.eof()) break;
    }
    return 0;
}
