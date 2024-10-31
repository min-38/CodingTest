#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted;

void merge(vector<int> *data, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end) {
        if((*data)[i] <= (*data)[j]) {
            sorted[k] = (*data)[i];
            i++;
        } else {
            sorted[k] = (*data)[j];
            j++;
        }
        k++;
    }

    if(i > mid) {
        for(int t = j; t <= end; t++) {
            sorted[k] = (*data)[t];
            k++;
        }
    } else {
        for(int t = i; t <= mid; t++) {
            sorted[k] = (*data)[t];
            k++;
        }
    }

    // 정렬된 배열을 삽입
    for(int t = start; t <= end; t++)
        (*data)[t] = sorted[t];
}

void merge_sort(vector<int> *data, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        merge_sort(data, start, mid); // 좌측 정렬
        merge_sort(data, mid + 1, end); // 우측 정렬
        merge(data, start, mid, end);
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> v(N, 0);
    sorted.resize(N, 0);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    merge_sort(&v, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d\n", v[i]);

    return 0;
}
