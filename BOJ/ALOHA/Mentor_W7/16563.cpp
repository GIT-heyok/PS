#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
bool isPrime[2241];
vector<int> primeLst[1000001];
// 16563 어려운 소인수분해
int main() {
    FAST
    // 에라토스테네스의 체 구현
    for (int i = 0; i <= 2240; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= 2240; ++i) { // 최적화 1. 굳이 10000까지 다 돌 필요 없음
        if(isPrime[i]){
            for (int j = i*i; j <= 2240; j+=i) { // 최적화 2. i^2 전까지는 다 이전에 계산이 되어있음
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 0; i <= 2240; ++i) {
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (int j = 0; j < primes.size(); ++j) {
            while(arr[i]%primes[j]==0){
                primeLst[i].push_back(primes[j]);
                arr[i]/=primes[j];
            }
        }
        if(arr[i]!=1){
            primeLst[i].push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < primeLst[i].size(); ++j) {
            cout<<primeLst[i][j]<<" ";
        }
        cout<<endl;
    }

}
