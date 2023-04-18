#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;

const int MAX = 1121;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 9901;

//dp with the order of small prime->large prime
int main(){
    FAST
    bool isPrime[MAX];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i<MAX; i++){
        if(isPrime[i]){
            for (int j = i*i; j < MAX; j+=i)
            {
                isPrime[j] = false;
            }
            
        }
    }
    vector<int> primes;
    primes.push_back(0);
    for (int i = 0; i < MAX; i++)
    {
        if(isPrime[i])primes.push_back(i);
    }
    int memo[1121][15];
    fill(&memo[0][0], &memo[1120][15], 0);
    memo[0][0] = 1;
    for (int i = 1; i < primes.size(); i++)
    {
        for (int j = MAX-1; j >= primes[i]; j--)
        {
            for (int k = 1; k <= 14; k++)
            {
                memo[j][k] += memo[j-primes[i]][k-1];
            }
            
        }
        
        
    }
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        cout<<memo[n][k]<<endl;
    }
    
}