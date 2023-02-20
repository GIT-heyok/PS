#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

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
const int MAX = 500001;
const int INF = 123456780;

int main()
{
    FAST
    int n;
    cin >> n;
    int arr[n][3];
    int memo[n][3][3];
    for(int i=0; i<n; i++){
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            for (int l = 0; l < 3; l++)
            {
            memo[i][j][l]= INF;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        memo[0][i][i] = arr[0][i];
    }

    //1. you cannot choose nth element if first one is picked
    for (int i = 1; i < n-1; i++)
    {
        for (int fir = 0; fir < 3; fir++)
        {
            memo[i][0][fir] = min(memo[i-1][1][fir], memo[i-1][2][fir])+arr[i][0];
            memo[i][1][fir] = min(memo[i-1][0][fir], memo[i-1][2][fir])+arr[i][1];
            memo[i][2][fir] = min(memo[i-1][0][fir], memo[i-1][1][fir])+arr[i][2];
        }
    }
    
            
    memo[n-1][0][0] = INF; 
    memo[n-1][1][0] = min(memo[n-2][0][0], memo[n-2][2][0])+arr[n-1][1]; 
    memo[n-1][2][0] = min(memo[n-2][0][0], memo[n-2][1][0])+arr[n-1][2];
    memo[n-1][0][1] = min(memo[n-2][1][1], memo[n-2][2][1])+arr[n-1][0]; 
    memo[n-1][1][1] = INF; 
    memo[n-1][2][1] = min(memo[n-2][0][1], memo[n-2][1][1])+arr[n-1][2]; 
    memo[n-1][0][2] = min(memo[n-2][1][2], memo[n-2][2][2])+arr[n-1][0]; 
    memo[n-1][1][2] = min(memo[n-2][0][2], memo[n-2][2][2])+arr[n-1][1]; 
    memo[n-1][2][2] = INF; 
    int ans= INF;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans = min(ans, memo[n-1][i][j]);
        }
        
    }
    cout<<ans<<endl;
}