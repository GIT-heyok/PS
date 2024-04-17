#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

// 11729 하노이 탑 이동 순서
// 처음, 중간, 끝을 정해준다.
void moveHanoi(int from, int middle, int to, int height) {
    if (height == 1) { // 기저 사례: 옮길 원판이 한개 밖에 없다. (옮길 칸은 비어 있다고 가정)
        cout << from << " " << to << endl; // 현재 있는 곳에서 원하는 곳으로 옮겨 준다.
    } else {
        moveHanoi(from, to, middle, height - 1); //우선 내 위에 있는것들을 다 중앙으로 치워 준다.
        cout << from << " " << to << endl; // 옮길 곳이 비어 있으니 옮겨 준다.
        moveHanoi(middle, from, to, height - 1); // 중앙에 있던 것들을 다시 그 곳으로 옮긴다.
    }
}

int main() {
    FAST
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    moveHanoi(1, 2, 3, n);
}

