#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n' // \n도 써줘야함.
// 26152 플래피 버드 스코어링
int main(void) {
    FAST // 빠른 입출력 구현 해 주어야 함.
    int n;
    cin >> n;
    int width[n];
    for (int i = 0; i < n; ++i) {
        cin >> width[i];
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        width[i] -= temp;
    }
    width[0]*=-1;
    for (int i = 1; i < n; ++i) {
        width[i] = min(width[i], -width[i-1]); // -테크닉: 내림차순으로 정렬
        width[i] *= -1;
    }
    // 이 연산이 끝난 후, width는 지나갈 수 있는 최대 크기 * -1의 값을 가진다.
    // ex) -9 -6 -6 -6 -3 -3 -1

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        cout<<upper_bound(width, width+n, -temp)-width<<endl;
        // upperbound-width : 위의 예시에서 -6이라면 O O O O X X X 중 O의 개수이다.
    }
}
