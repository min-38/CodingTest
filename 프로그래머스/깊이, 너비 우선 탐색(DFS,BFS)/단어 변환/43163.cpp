#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    string word;
    int length;
};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int wl = target.length();
    
    bool exist = false;
    for(int i = 0; i < words.size(); i++)
        if(words[i] == target) {
            exist = true;
            break;
        }

    if(exist) {
        vector<bool> visited(words.size(), false);
        int matched = 0;
        
        Node rootNode;
        rootNode.word = begin;
        rootNode.length = 0;
        
        queue<Node> q;
        q.push(rootNode);
        
        while(!q.empty()) {
            Node n = q.front();
            q.pop();

            if(n.word == target)
                if(answer == 0 || n.length < answer)
                    answer = n.length;
            
            for(int i = 0; i < words.size(); i++) {
                if(visited[i])
                    continue;
                
                matched = 0;
                for(int j = 0; j < words[i].length(); j++)
                    if(n.word[j] == words[i][j])
                        matched++;
                
                if(matched >= wl - 1) {
                    Node newNode = n;
                    newNode.word = words[i];
                    newNode.length++;
                    
                    q.push(newNode);
                    visited[i] = true;
                }
            }
        }
    }
    return answer;
}