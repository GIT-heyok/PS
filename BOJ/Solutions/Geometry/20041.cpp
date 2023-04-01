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
typedef pair<double, double> pD;

const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int main(){
	FAST
    ll dr[4] = {0,0,-1,1};
    ll dc[4] = {-1,1,0,0};

    int n;
    cin >> n;
    ll polr[n], polc[n];
    for (int i = 0; i < n; i++)
    {
        cin >> polr[i] >> polc[i];
    }
    
    ll r, c;
    cin >> r >> c;
    bool chk[4]={true, true, true, true};
    //up
    for (int i = 0; i < n; i++)
    {
        if(polr[i]-r>0&&polr[i]-r>=abs(c-polc[i])){
            chk[0] = false;
        }
    }
    //down
    for (int i = 0; i < n; i++)
    {
        if(r-polr[i]>0&&r-polr[i]>=abs(c-polc[i])){
            chk[1] = false;
        }
    }//up
    for (int i = 0; i < n; i++)
    {
        if(polc[i]-c>0&&polc[i]-c>=abs(r-polr[i])){
            chk[2] = false;
        }
    }//up
    for (int i = 0; i < n; i++)
    {
        if(c-polc[i]>0&&c-polc[i]>=abs(r-polr[i])){
            chk[3] = false;
        }
    }
    bool chkk = chk[0];
    chkk |= chk[1];
    chkk |= chk[2];
    chkk |= chk[3];
    if(chkk)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


