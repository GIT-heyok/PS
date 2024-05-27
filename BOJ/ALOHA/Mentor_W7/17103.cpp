#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
bool isPrime[1000001];
// 17103 골드바흐 파티션
int main() {
    FAST
    // 에라토스테네스의 체 구현
    for (int i = 0; i <= 1'000'000; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= 1'000'000 ; ++i) { // 최적화 1. 굳이 10000까지 다 돌 필요 없음
        if(isPrime[i]){
            for (int j = i*i; j <= 1'000'000 ; j+=i) { // 최적화 2. i^2 전까지는 다 이전에 계산이 되어있음
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 0; i <= 1'000'000; ++i) {
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        int temp;
        cin >> temp;
        for (int j = 0; j < primes.size(); ++j) {
            int p = primes[j];
            if(temp < 2*p){
                break;
            }
            if(isPrime[temp-p])
            cnt++;
        }
        cout<<cnt<<endl;

    }

}
