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
const int MAX = 100002;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
struct INFO {
    ll x, y;
    ll p, q;
    INFO(ll x1 = 0, ll y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};
 
bool comp(const INFO &A, const INFO &B) {
    if (1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p*B.q;
 
    if (A.y != B.y)
        return A.y < B.y;
 
    return A.x < B.x;
}
 
ll ccw(const INFO &A, const INFO &B, const INFO &C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}
 
INFO p[MAX];
 
int main(){
	FAST
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        p[i] = INFO(x, y);
    }
 
    sort(p, p + n, comp);
 
    for (int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
 
    sort(p + 1, p + n, comp);
 
    stack<int> st;
 
    st.push(0);
    st.push(1);
 
    int next = 2;
 
    while (next < n) {
        while (st.size() >= 2) {
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();
 
            if (ccw(p[first], p[second], p[next]) > 0) {
                st.push(second);
                break;
            }
        }
 
        st.push(next++);
    }
    cout<<st.size()<<endl;
    


}


