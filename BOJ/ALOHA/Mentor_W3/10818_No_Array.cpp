#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
// 10818 최소, 최대
int main()
{
    FAST
    int n;
    cin >> n;
    int mnm = 1000001, mxm = -1000001; //초기 값을 설정해준다.
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t; // 배열에 저장할 필요는 없다.
        if(mnm > t){ // 최솟값보다 더 작은 값을 찾았다.
            mnm = t;
        }
        if(mxm < t){ // 최댓값보다 더 큰 값을 찾았다.
            mxm = t;
        }
    }
    cout<< mnm << " " << mxm << endl;
}
