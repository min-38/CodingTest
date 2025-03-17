#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int num;
    Node* next = nullptr;
    Node* prev  = nullptr;
    Node(int num, Node* prev, Node* next) : num(num), prev(prev), next(next) {}
};

stack<Node*> trash;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');

    // 테이블 생성
    Node* cursor = new Node(0, nullptr, nullptr);
    for (int i = 1; i < n; i++)
    {
        cursor->next = new Node(i, cursor, NULL);
        cursor = cursor->next;
    }

    // k로 커서 이동
    for(int i = 0; i < n - k - 1; i++)
        cursor = cursor->prev;

    for(string str : cmd)
    {
        if(str[0] == 'U' || str[0] == 'D')
        {
            int x = stoi(str.substr(2));
            if(str[0] == 'U')
                while(x--)
                    cursor = cursor->prev;
            else
                while(x--)
                    cursor = cursor->next;
        }
        else if(str[0] == 'C')
        {
            trash.push(cursor);
            
            if(cursor->prev != NULL)
                cursor->prev->next = cursor->next;
            
            if(cursor->next != NULL)
                cursor->next->prev = cursor->prev;
            
            if(cursor->next == NULL)
                cursor = cursor->prev;
            else
                cursor = cursor->next;
        }
        else
        {
            Node* node = trash.top();
            trash.pop();

            if(node->prev != NULL)
                node->prev->next = node;
            if(node->next != NULL)
                node->next->prev = node;
        }
    }

    answer[cursor->num] = 'O';
    while(cursor->prev != NULL) {
        answer[cursor->prev->num] = 'O';
        cursor = cursor->prev;
    }
    while(cursor->next != NULL) {
        answer[cursor->next->num] = 'O';
        cursor = cursor->next;
    }
    
    return answer;
}
