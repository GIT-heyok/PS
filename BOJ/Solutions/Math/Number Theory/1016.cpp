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
const int MAX = 21;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 9999991;
/*
brute force!
could be faster with eratosthenes' sieve
*/
int main()
{

    bool isPrime[1000001];

    fill(isPrime, isPrime+1000001, 1);
    isPrime[0] =false;
    isPrime[1] = false;
    for(int i=2; i*i<=1000000; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                isPrime[j] = false;
            }
        }
    }
    FAST
    ll a, b;
    cin >> a >> b;
    bool isJegobNN[b-a+1];
    fill(isJegobNN, isJegobNN+b-a+1, true);
    for (ll i = 2; i <= 1000000; i++)
    {
        if(!isPrime[i])continue;
        ll sq = i*i;
        for (ll j = (a+sq-1)/sq*sq; j <= b ; j+=sq)
        {
            isJegobNN[j-a]=false;   
        }
    }
    ll cnt = 0;
    for (int i = 0; i < b-a+1; i++)
    {
        if(isJegobNN[i])cnt++;
    }
    cout<<cnt<<endl;
    
    
} 