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
const int MAX = 50001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;

const int MAXN = 1000010;

int z[MAXN];

void get_z(string& S) {
    int N = S.length();
	z[0] = N;	// 그냥 의미상 N
	int L = 0, R = 0;
	for(int i = 1; i < N; i++) {
		if(R < i) {
			for(z[i] = 0; S[z[i]] == S[i + z[i]]; z[i]++);
			L = i;
			R = i + z[i] - 1;
		}
		else {
			if(z[i - L] <= R - i) z[i] = z[i - L];
			else {
				for(z[i] = R - i + 1; S[z[i]] == S[i + z[i]]; z[i]++);
				L = i;
				R = i + z[i] - 1;
			}
		}
	}
}
int main()
{
    FAST
        string s;
    cin >> s;
    reverse(all(s));
    get_z(s);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cout << z[s.length()-temp] << endl;
    }
}

