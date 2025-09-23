#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinaryString(int n, int OrCal)
{
    string binary = "";
    
    while (OrCal > 0)
    {
        binary += (OrCal % 2 == 0 ? " " : "#");
        OrCal /= 2;
    }

    while (binary.length() < n)
        binary += " ";

    reverse(binary.begin(), binary.end());
    return binary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++)
    {
        int OrCal = arr1[i] | arr2[i];
        answer.push_back(toBinaryString(n, OrCal));
    }
    
    return answer;
}