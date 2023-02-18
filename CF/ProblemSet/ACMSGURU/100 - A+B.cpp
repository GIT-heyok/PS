#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int MAX = 500001;
const int INF = 1234567890;

int main(){
    FAST
    int k;
    cin >> k;
    ll fib[42];
    fib[1] = 1;
    fib[2] = 1;
    for(int i=3; i<=41; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    ll ans = 0;
    for(int i=1; i<=k; i++){
        ans += fib[i];
    }
    cout<<ans<<endl;
}

    