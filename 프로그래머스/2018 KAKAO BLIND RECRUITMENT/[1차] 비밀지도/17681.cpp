#include <string>
#include <vector>

using namespace std;

string getWall(int n, int num) {
    vector<char> binaries(n);
    int idx = n - 1;
    while (num >= 2)
    {
        binaries[idx--] = (num % 2) + '0';
        num /= 2;
    }
    binaries[idx] = num + '0';

    string str = "";
    for (char c : binaries)
        if (c == '1')
            str += '#';
        else
            str += ' ';
    
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    for (int i = 0; i < n; i++)
        answer[i] = getWall(n, arr1[i]);
        
    for (int i = 0; i < n; i++)
    {
        string newString = getWall(n, arr2[i]);
        string& line = answer[i];
        
        for (int j = 0; j < n; j++)
        {
            if (line[j] == '#') continue;
            
            if (newString[j] == '#')
                line[j] = '#';
        }
    }
        
    return answer;
}