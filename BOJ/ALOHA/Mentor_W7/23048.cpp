#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
// 23048 자연수색칠하기
int main() {
    FAST
    int n;
    cin >> n;
    int isPrime[n+1];
    // 에라토스테네스의 체 구현
    for (int i = 0; i <= n; ++i) {
        isPrime[i] = -1;
    }
    int curMx = 1;
    isPrime[1] = 1;
    for (int i = 2; i <= n; ++i) { // 최적화 1. 굳이 10000까지 다 돌 필요 없음
        if(isPrime[i]==-1){
            curMx++;
            isPrime[i] = curMx;
            for (ll j = (ll)i*i; j <= (ll)n; j+=i) { // 최적화 2. i^2 전까지는 다 이전에 계산이 되어있음
                isPrime[j] = isPrime[i];
            }
        }
    }

    cout<<curMx<<endl;
    for (int i = 1; i <= n; ++i) {
        cout<<isPrime[i]<<" ";
    }
    cout<<endl;
}
