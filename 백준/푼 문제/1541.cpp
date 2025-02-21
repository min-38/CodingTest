#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> v;

    string tmp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == delimiter)
        {
            v.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += str[i];
    }

    if (tmp != "")
        v.push_back(tmp);
    
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<string> A = split(str, '-');

    int result = 0;

    for(int i = 0; i < A.size(); i++) {
        vector<string> B = split(A[i], '+');
        
        int num = 0;
        for (string s : B)
            num += stoi(s);

        if (i == 0)
            result += num;
        else
            result -= num;
    }
    
    cout << result << "\n";

    return 0;
}