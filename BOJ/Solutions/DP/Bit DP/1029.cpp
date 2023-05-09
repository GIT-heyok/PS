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
const int MAX = 15;
const double INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;
int arr[MAX][MAX];
int n;
int memo[MAX][1<<MAX][10];
/*
이 왜 맞 ㅋㅋ
*/
int dfs(int cur, int bit, int curVal){
    int& temp = memo[cur][bit][curVal];
    if(temp!=-1)return temp;
    temp = 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[cur][i]<curVal)continue;//check for condition
        if(bit&(1<<i))continue;//check if already visited
        temp = max(temp, 1+dfs(i,bit+(1<<i), arr[cur][i]));
    }
    return temp;
    
}
int main()
{
    FAST 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j]= s[j]-'0';
        }
    }

    
    fill(&memo[0][0][0], &memo[MAX-1][(1<<MAX)-1][10], -1);
    cout<<dfs(0,1,0)<<endl;
    

    
}
