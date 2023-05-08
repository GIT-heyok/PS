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
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;

vector<int> triangles;
bool isPossible[1001];
int main()
{
    FAST int T;
    cin >> T;
    for (int i = 0; i < 1001; i++)
    {
        isPossible[i] = false;
    }
    isPossible[0] = true;
    for (int i = 1; i * (i + 1) / 2 < 1000; i++)
    {
        triangles.push_back(i * (i + 1) / 2);
    }
    
    
    for (int j : triangles)
        for (int k : triangles)
            for (int l : triangles)
                if (j + k + l <= 1000)
                    isPossible[j + k + l] = true;

    while (T--)
    {
        int n;
        cin >> n;
        cout << isPossible[n] << endl;
    }
}
