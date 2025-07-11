#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
map<string, vector<pair<string, bool>>> adj;
int num_tickets = 0;

bool dfs(const string& from, vector<string>& path)
{
    path.push_back(from);

    if (path.size() == num_tickets + 1)
    {
        answer = path;
        return true;
    }

    if (adj.count(from))
        for (auto& edge : adj.at(from))
        {
            string to = edge.first;
            bool& is_used = edge.second;

            if (!is_used) {
                is_used = true;
                if (dfs(to, path)) return true;
                is_used = false;
            }
        }

    path.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    num_tickets = tickets.size();

    // 목적지 세팅
    for (const auto& ticket : tickets)
        adj[ticket[0]].push_back({ticket[1], false});

    // 목적지를 알파벳 순서로 정렬
    for (auto& entry : adj)
        sort(entry.second.begin(), entry.second.end());

    vector<string> current_path;
    dfs("ICN", current_path);

    return answer;
}