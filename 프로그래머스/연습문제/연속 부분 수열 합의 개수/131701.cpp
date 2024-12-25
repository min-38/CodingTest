#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> results;
int nodeCnt;

struct node {
    int element;
    node* next;
};

class LinkedList {
private:
    node* head;
    node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(int element);
    int getValue(node* n);
    void calculate(int length);
};

void LinkedList::addNode(int element) {
    node* temp = new node;
    temp->element = element;

    if (head == NULL) {
		head = temp;
        tail = head;
	} else {
		tail->next = temp;
        tail = temp;
        tail->next = head;
	}
}
int LinkedList::getValue(node* n) {
    return n->element;
}
void LinkedList::calculate(int length) {
    node* startNode = head;
    int loopCnt = nodeCnt;
    if(length == nodeCnt) {
        loopCnt = 1;
    }
    int value;
    for(int i = 0; i < loopCnt; i++) {
        value = 0;
        node* n = startNode;
        for(int j = 0; j < length; j++) {
            value += getValue(n);
            n = n->next;
        }
        results.push_back(value);
        startNode = startNode->next;
    }
}
int solution(vector<int> elements) {
    int answer = 0;
    
    LinkedList ll;
    nodeCnt = elements.size();
    for(int element : elements) {
        ll.addNode(element);
    }

    int length = 1;
    while(length <= nodeCnt) {
        ll.calculate(length);
        length++;
    }

    sort(results.begin(), results.end());

    int prev_value = 0;
    for(int result : results) {
        if(prev_value == result) {
            continue;
        }
        answer++;
        prev_value = result;
    }
    return answer;
}
