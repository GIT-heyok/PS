#include <bits/stdc++.h>

using namespace std;
// 2750 수 정렬하기
int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // array 에서의 정렬법
    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}
