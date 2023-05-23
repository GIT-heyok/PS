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
const int MAX = 4000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int main()
{
    FAST
    int k, n;
    cin >> k >> n;
    vector<int> primes;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        primes.push_back(temp);
        pq.push(-temp);
    }
    
    int cur = 0;
    int curNum = -1;
    while(cur<n){
        int now = -pq.top();
        pq.pop();
        if(now==curNum){
            continue;
        }
        else{
            curNum=now;

            cur++;
            for (int i = 0; i < k; i++)
            {
                if((ll)now*primes[i]>=(1LL<<31))continue;
                pq.push(-now*primes[i]);
            }
            
        }
    }
    cout<<curNum<<endl;
} 