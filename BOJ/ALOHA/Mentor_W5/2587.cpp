#include <bits/stdc++.h>

using namespace std;
// 2587 대표값2
int main(void) {
    vector<int> vec(5);
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> vec[i];
        sum += vec[i];
    }
    sort(vec.begin(), vec.end()); // 벡터 정렬
    cout << sum/5 << endl; // 평균
    cout << vec[2] << endl; // 중앙값
}
