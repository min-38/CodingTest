#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    cout << gcd(A, B) << "\n"; // 최대 공약수

    int A_c = A;
    int B_c = B;

    while (A_c != B_c) {
        if (A_c > B_c)  // B가 A보다 작으면
            B_c += B;
        else        // A가 B보다 작으면
            A_c += A;
    }

    cout << A_c << "\n"; // 최소 공배수

    return 0;
}