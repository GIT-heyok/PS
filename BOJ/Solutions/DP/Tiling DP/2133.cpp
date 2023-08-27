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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;
int main() {
    FAST
    int n;
    cin >> n;
    if(n%2){
        cout<<0<<endl;
    }
    else{
        int arr[n][5];
        arr[0][0] = 1;
        arr[0][1]= 1;
        arr[0][2] = 0;
        arr[0][3]= 0;
        arr[0][4] = 3;
        for (int i = 1; i < n; i++)
        {
            arr[i][1] = arr[i-1][3];
            arr[i][0] = arr[i-1][2];
            arr[i][2] = arr[i-1][0]+arr[i-1][4];
            arr[i][3] = arr[i-1][1]+arr[i-1][4];
            arr[i][4] = arr[i-1][3]+arr[i-1][2];
            if(i-2>=0)arr[i][4]+=arr[i-2][4];
        }
        
        cout<<arr[n-2][4]<<endl;
        
   }
}