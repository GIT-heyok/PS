#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
bool isPrime[10001];
// 24039 2021은 무엇이 특별할까?
int main() {
    FAST
    // 에라토스테네스의 체 구현
    for (int i = 0; i < 10001; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= 10000; ++i) { // 최적화 1. 굳이 10000까지 다 돌 필요 없음
        if(isPrime[i]){
            for (int j = i*i; j <= 10000; j+=i) { // 최적화 2. i^2 전까지는 다 이전에 계산이 되어있음
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 0; i <= 10000; ++i) {
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    int n;
    cin >> n;

    for (int i = 0; i < primes.size(); ++i) {
        if(primes[i]*primes[i+1]>n){
            cout<<primes[i]*primes[i+1]<<endl;
            break;
        }
    }

}
