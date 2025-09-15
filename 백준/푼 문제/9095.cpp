#include <iostream>
#include <stack>

using namespace std;

int main() {
    
    // 테스트 케이스 입력 받기
    int T;
    cin >> T;

    while (T--)
    {
        // 정수 n 입력 받기
        int n;
        cin >> n;

        stack<int> st;

        st.push(1);
        st.push(2);
        st.push(3);

        int result = 0;
        while (!st.empty())
        {
            int val = st.top();
            st.pop();

            if (val == n)
            {
                result++;
                continue;
            }

            if (val + 1 <= n)
                st.push(val + 1);
            
            if (val + 2 <= n)
                st.push(val + 2);

            if (val + 3 <= n)
                st.push(val + 3);
        }

        cout << result << endl;
    }

    return 0;
}