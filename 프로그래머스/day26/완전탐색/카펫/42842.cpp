#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    // 격자의 총 개수 (갈색 격자 + 노란색 격자)
    int total_size = brown + yellow;
    // 세로 길이의 범위는 3부터 (갈색 격자 + 노란색 격자)의 제곱근
    for(int vertical = 3; vertical <= sqrt(total_size); ++vertical) {
        // 사각형 구성이 되는지 확인
        if(total_size % vertical == 0) {
            int horizontal = total_size / vertical; // 사각형의 가로 길이
            // 카펫 형태로 만들 수 있는지 확인
            if(brown == (horizontal + vertical - 2) * 2) {
                return {horizontal, vertical}; // {가로 길이, 세로 길이}
            }
        }
    }
    return {}; // 만약 답을 찾지 못했다면 빈 벡터를 반환
}