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
    int n;
    cin >> n;
    int arr[n]; // 길이가 n인 배열을 생성한다.
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // 배열 안에 넣어준다.
    }
    int mnm = arr[0], mxm = arr[0]; //초기 값을 설정해준다.
    for (int i = 0; i < n; ++i) {
        if(mnm > arr[i]){ // 최솟값보다 더 작은 값을 찾았다.
            mnm = arr[i];
        }
        if(mxm < arr[i]){ // 최댓값보다 더 큰 값을 찾았다.
            mxm = arr[i];
        }
    }
    cout<< mnm << " " << mxm << endl;
}
