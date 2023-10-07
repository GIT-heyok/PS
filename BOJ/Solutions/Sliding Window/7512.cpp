#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

bool isPrime[10000001];

int main() {
    FAST
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i * i <= 10000000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 10000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i < 10000000; ++i) {
        if (isPrime[i])primes.push_back(i);
    }
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; ++TC) {
        vector<ll> candidate;
        for (int i:primes) {
            candidate.push_back(i);
        }
        vector<ll> ans;
        int m;
        cin >> m;
        int arr[m];
        for (int i = 0; i < m; ++i) {
            cin >> arr[i];
        }

        for (int i = 0; i < m; ++i) {
            ll sum = 0;
            for (int j = 0; j < primes.size(); ++j) {
                sum+=primes[j];
                if(j>=arr[i])sum-=primes[j-arr[i]];
                if(j>=arr[i]-1){
                    if((*lower_bound(candidate.begin(), candidate.end(), sum))==sum){
                        ans.push_back(sum);
                    }
                }
                if(sum>=10000000)break;
            }
            candidate.clear();
            for (long long an : ans) {
                candidate.push_back(an);
            }
            ans.clear();
        }
        cout<<"Scenario "<<TC<<":"<<endl;
        cout<<candidate[0]<<endl<<endl;
    }

}