#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

// 24460 특별상이라도 받고 싶어
int n; // n은 재귀함수에서 사용될 것이기 떄문에 전역 변수로 선언 해준다.
int arr[1024][1024]; // N은 최대 2^10 = 1024이다.

// 두번째로 작은 숫자를 구해보자.
int getSecondSmallestNumber(int n1, int n2, int n3, int n4) {
    int mnm = min(n1, min(n2, min(n3, n4))); // max 함수로 최댓값을 우선 구한다.
    int secondMnm = 2147483647; // 2^31 보다 작은 가장 큰 정수이다 (int 범위에서는 가장 크다. long long을 썼으면 더욱 간편히 숫자를 사용할 수 있다.)

    if (n1 != mnm) { // min이 아닌 것 중 가장 작은 것을 찾아보자.
        secondMnm = min(secondMnm, n1);
    }
    if (n2 != mnm) { // min이 아닌 것 중 가장 작은 것을 찾아보자.
        secondMnm = min(secondMnm, n2);
    }
    if (n3 != mnm) { // min이 아닌 것 중 가장 작은 것을 찾아보자.
        secondMnm = min(secondMnm, n3);
    }
    if (n4 != mnm) { // min이 아닌 것 중 가장 작은 것을 찾아보자.
        secondMnm = min(secondMnm, n4);
    }

    return secondMnm;
}

// 현재 다루는 범위를 r1: 가장 위의 열 r2: 가장 아래의 행, c1: 가장 왼쪽 행, c2: 가장 오른쪽의 행 으로 정의하자.
int recursion(int r1, int r2, int c1, int c2) {
    if (r1 == r2 && c1 == c2) return arr[r1][c1]; // 기저 사례 1*1의 배열이다.
    if (r2 - r1 == 1 && c2 - c1 == 1) { // 기저 사례: 2*2의 배열이 뽑혔다.
        int n1 = arr[r1][c1]; // 왼쪽 위
        int n2 = arr[r1][c2]; // 오른쪽 위
        int n3 = arr[r2][c1]; // 왼쪽 아래
        int n4 = arr[r2][c2]; // 오른쪽 아래
        return getSecondSmallestNumber(n1, n2, n3, n4);
    }
    int rMid = (r1 + r2) / 2; //중앙 값을 설정해준다. [r1,rMid]: 절반 중 왼쪽, [rMid+1, r2]: 절반 중 오른쪽
    int cMid = (c1 + c2) / 2;

    // 위의 n들은 if 안에서만 작동하기 때문에 여기서 다시 선언해도 문제가 없다.
    int n1 = recursion(r1, rMid, c1, cMid); // 왼쪽 위 부분
    int n2 = recursion(r1, rMid, cMid + 1, c2); // 오른쪽 위 부분
    int n3 = recursion(rMid + 1, r2, c1, cMid); // 왼쪽 아래 부분
    int n4 = recursion(rMid + 1, r2, cMid + 1, c2); // 오른쪽 아래 부분
    return getSecondSmallestNumber(n1, n2, n3, n4); // 이 범위 중에서 두번째로 작은 숫자를 반환한다.
}

int main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << recursion(0, n - 1, 0, n - 1) << endl;
}

    