#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    string str;
    int seq;
};

int solution(string s) {
    int answer;
    
    int sLength = s.length();
    answer = s.length();
    
    int unit = 1;
    int limit = sLength / 2;
    
    while (unit <= sLength)
    {
        queue<Node> q;
        for (int i = 0; i < sLength; i += unit)
        {
            string new_str = "";
            for (int j = i; j < i + unit; j++)
            {
                if (j >= sLength)
                    break;
                new_str += s[j];
            }

            if (q.empty())
            {
                q.push({new_str, 1});
                continue;
            }
            
            Node& n = q.back();
            if (n.str == new_str)
            {
                n.seq += 1;
                continue;
            }
            q.push({new_str, 1});
        }
        
        string tmp = "";
        while (!q.empty())
        {
            Node n = q.front();
            q.pop();
            
            if (n.seq > 1)
                tmp += to_string(n.seq);
            tmp += n.str;
        }
        
        if (tmp.length() < answer)
            answer = tmp.length();

        unit++;
    }
    return answer;
}