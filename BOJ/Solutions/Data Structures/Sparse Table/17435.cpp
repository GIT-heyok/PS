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
    int m;
    cin >> m;
    int arr[20][m+1];
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[0][i];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = arr[i-1][arr[i-1][j]];
        }
    }

   // for (int i = 0; i < 20; i++)
   // {
   //     cout<<(1<<i)<<" : ";
   //     for (int j = 1; j <= m; j++)
   //     {
   //         cout<<arr[i][j]<<" ";
   //     }
   //     cout<<endl;
   //     
   // }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int cur = b;
        for (int i = 0; i < 20; i++)
        {
            if(a&(1<<i)){
                cur = arr[i][cur];
            }
        }
        cout<<cur<<endl;
        
    }
    
    
    
}


