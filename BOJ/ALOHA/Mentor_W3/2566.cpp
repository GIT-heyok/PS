#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    FAST
    int arr[10][10]; // 9행 9열짜리의 배열을 생성한다. (배열의 위치를 위해서 넉넉하게 크기를 잡는다.)

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) { // 배열의 크기를 크게 잡았기 때문에 1~9까지 잡아도 괜찮다.
            cin >> arr[i][j]; // i열 j행에 입력받는다.
        }
    }
    int mxm = arr[1][1]; // 초기값을 설정한다.
    int r = 1, c = 1; // 위치를 저장할 초기값을 설정한다.
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) { // 배열의 크기를 크게 잡았기 때문에 1~9까지 잡아도 괜찮다.
            if(mxm < arr[i][j]){
                mxm = arr[i][j];
                r = i;
                c = j; // mxm이 바뀌었기 때문에 r과 c를 재설정한다.
            }
        }
    }
    cout << mxm << endl;
    cout << r << " " << c << endl;
}
