#include <iostream>
#include <vector>

using namespace std;

vector<char> answer;
vector<int> myStack;

void add(int num) {
    myStack.push_back(num);
    answer.push_back('+');
}

void remove() {
    myStack.pop_back();
    answer.push_back('-');
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        add(i);

        while (myStack.size() > 0 && myStack.back() == arr[idx]) {
            remove();
            idx++;
        }
    }

    if (myStack.size() > 0) {
        cout << "NO" << "\n";
    } else {
        for (char c : answer) {
            cout << c << "\n";
        }
    }


    return 0;
}