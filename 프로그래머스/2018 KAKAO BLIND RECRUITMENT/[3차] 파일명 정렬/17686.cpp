#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    string HEAD;
    string NUMBER;
    int i_NUMBER;
    string TAIL;
    int seq; // 순서
};

bool cmp (Node& n1, Node& n2)
{
    // 1. HEAD 부분을 비교하기 위해 둘 다 소문자로 변경
    string head1_lower = n1.HEAD;
    transform(head1_lower.begin(), head1_lower.end(), head1_lower.begin(), ::tolower);

    string head2_lower = n2.HEAD;
    transform(head2_lower.begin(), head2_lower.end(), head2_lower.begin(), ::tolower);

    // 2. HEAD가 다르면 HEAD 기준으로 정렬
    if (head1_lower != head2_lower)
        return head1_lower < head2_lower;

    // 3. HEAD가 같으면 NUMBER 기준으로 정렬
    if (n1.i_NUMBER != n2.i_NUMBER)
        return n1.i_NUMBER < n2.i_NUMBER;

    // 4. HEAD와 NUMBER가 모두 같으면 원래 순서 유지
    return n1.seq < n2.seq;
}  

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<Node> v;
    for (int i = 0; i < files.size(); i++)
    {
        string file = files[i];

        Node newNode;
        string str;
        int j = 0;

        // HEAD 찾기
        for ( ; j < file.length(); j++)
        {
            char c = file[j];
            if (c >= 48 && c <= 59)
                break;
            str += c;
        }
        newNode.HEAD = str;
        str = "";

        // NUMBER 찾기
        for ( ; j < file.length(); j++)
        {
            char c = file[j];
            if (c >= 48 && c <= 59)
            {
                str += c;
                continue;
            }
            break;
        }
        newNode.NUMBER = str;
        newNode.i_NUMBER = stoi(str);
        str = "";

        // TAIL 찾기
        for ( ; j < file.length(); j++)
            str += file[j];
        newNode.TAIL = str;

        // 순서 기억
        newNode.seq = i;
        
        v.push_back(newNode);
    }

    sort(v.begin(), v.end(), cmp);

    for (Node& n : v)
        answer.push_back(n.HEAD + n.NUMBER + n.TAIL);

    return answer;
}