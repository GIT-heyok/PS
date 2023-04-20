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

const int MAX = 1121;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 987654321;

int main()
{
    FAST int T = 3;
    while (T--)
    {
        int n;
        cin >> n;
        int coins[n][2];
        int K = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i][0] >> coins[i][1];
            K += coins[i][0] * coins[i][1];
        }
        if (K % 2 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            int MAX = K / 2 + 1;
            bool memo[MAX], visited[MAX];
            fill(memo, memo + MAX, 0);
            memo[0] = true;
            for (int i = 0; i < n; i++)
            {
                fill(visited, visited + MAX, 0);
                for (int j = 0; j < MAX; j++)
                {
                    int curCoin = coins[i][0]; // value of the current coin
                    int curSize = coins[i][1]; // amount of the current coin
                    if (!memo[j])
                        continue;
                    if(visited[j])continue;
                    int curIndex = j + curCoin;
                    while (curIndex < MAX && curSize > 0)
                    {
                        if (visited[curIndex])
                            break;
                        visited[curIndex] = true;
                        if (memo[curIndex])
                        {
                            curSize = coins[i][1];
                        }
                        else
                        {
                            curSize--;
                            memo[curIndex] = true;
                        }
                        curIndex += curCoin;
                    }
                    if(j==0)visited[0]=true;
                }
            }
            
            cout << memo[MAX - 1] << endl;
        }
    }
}