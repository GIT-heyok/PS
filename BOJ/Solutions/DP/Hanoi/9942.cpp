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
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e9+7;

//https://velog.io/@j1nhe0/PS-%EB%B0%B1%EC%A4%80-11729-1914-23250-9942-%ED%95%98%EB%85%B8%EC%9D%B4-%ED%83%91-C
int main(){
    FAST
    int n;
    int ccnt=0;
    while(cin >> n){
        ccnt++;
        ll ans = 0;
        int cnt = 0;
        int rcnt = 0;
        while(n>0){
            if(rcnt==0){
                rcnt=cnt+1;
                cnt++;
            }
            ans+=1ll<<(cnt-1);
            rcnt--;
            n--;
        }
        cout<<"Case "<<ccnt<<": "<<ans<<endl;
        
    }
}