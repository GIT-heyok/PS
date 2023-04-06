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

const int MAX = 101;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9;

//connected graph: always can be traveled with n-1

int main(){
	FAST
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int arr[n+1][n+1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = 0;   
            }
            
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        cout<<n-1<<endl;
        
        
    }
}


