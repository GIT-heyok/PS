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
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int memo[n][n][3];
    fill(&memo[0][0][0], &memo[n-1][n-1][3], 0);
    memo[0][1][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //horizontal
            if(j+1<n&&!arr[i][j+1]){
                memo[i][j+1][0]+=memo[i][j][0];
            }
            if(j+1<n&&i+1<n&&!arr[i+1][j+1]&&!arr[i+1][j]&&!arr[i][j+1]){
                memo[i+1][j+1][1]+=memo[i][j][0];
            }
            //diagonal 
            if(j+1<n&&!arr[i][j+1]){
                memo[i][j+1][0]+=memo[i][j][1];
            }
            if(j+1<n&&i+1<n&&!arr[i+1][j+1]&&!arr[i+1][j]&&!arr[i][j+1]){
                memo[i+1][j+1][1]+=memo[i][j][1];
            }
            if(i+1<n&&!arr[i+1][j]){
                memo[i+1][j][2]+=memo[i][j][1];
            }
            //vertical
            if(j+1<n&&i+1<n&&!arr[i+1][j+1]&&!arr[i+1][j]&&!arr[i][j+1]){
                memo[i+1][j+1][1]+=memo[i][j][2];
            }
            if(i+1<n&&!arr[i+1][j]){
                memo[i+1][j][2]+=memo[i][j][2];
            }
        }
        
    }
    cout<<memo[n-1][n-1][0]+memo[n-1][n-1][1]+memo[n-1][n-1][2];
}