#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> prime_numbers;
vector<bool> visited;
string g_numbers;

bool isPrime(int n)
{
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void dfs(string current_num)
{
    if (!current_num.empty()) {
        int num = stoi(current_num);
        if (isPrime(num)) {
            prime_numbers.insert(num);
        }
    }
    
    for (int i = 0; i < g_numbers.length(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(current_num + g_numbers[i]);
            visited[i] = false; // 백트래킹: 상태 복원
        }
    }
}

int solution(string numbers) {
    g_numbers = numbers;
    visited.assign(g_numbers.length(), false);
    
    dfs("");

    return prime_numbers.size();
}