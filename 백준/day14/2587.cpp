#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(5, 0);

    int avg = 0;
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
        avg += v[i];
    }

    int index;
    for(int i = 0; i < v.size(); i++) {
        index = i; // 최소값의 인덱스
        for(int j = i + 1; j < v.size(); j++)
            if(v[index] > v[j])
                index = j;
        
        int tmp = v[i];
        v[i] = v[index];
        v[index] = tmp;
    }

    cout << avg / v.size() << endl;
    cout << v[2] << endl;
    
    return 0;
}