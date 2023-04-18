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
//#define endl '\n'
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


int main(){
    FAST
    int T;
    cin >> T;
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
    
    int memo[MAX][15][primes.size()];
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i < primes.size(); i++)
    {
        memo[primes[i]][1][i]=1;
    }
    for (int i = 2; i <= 14 ; i++)//i is k's position
    {
        for (int j = 1; j < MAX; j++)//j is n's position, dp[]
        {
            for (int l = 1; l < primes.size(); l++)//l is p's position for modified ver
            {
                if(j-primes[l]>0){
                    for (int m = 1; m < primes.size(); m++)//m is p's position for previous ver
                    {
                        if(l>m)
                        memo[j][i][l] += memo[j-primes[l]][i-1][m];
                    }
                }
            }
            
        }
    }
    while(T--){
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 0; i < primes.size(); i++)
        {
            ans+=memo[n][k][i];
        }
        cout<<ans<<endl;
        
    }
    
    
}