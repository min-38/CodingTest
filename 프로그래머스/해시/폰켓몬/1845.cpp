#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    // s는 nums의 중복값을 제거한 집합
    unordered_set<int> s(nums.begin(), nums.end());
    // nums / 2의 개수와 s의 개수 중 작은 값을 반환
    return min(nums.size() / 2, s.size());
}