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

const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;

vector<int> tree[MAX];
int delay[MAX];
int inDegree[MAX];
int memo[MAX];
bool visited[MAX];

int main()
{
    FAST;
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> delay[i];
            inDegree[i] = 0;
            memo[i] = 0;
        }
        
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            tree[i].clear();
        }
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            inDegree[b]++;
        }
        int start = 0;
        for (int i = 1; i <= n; i++)
        {
            if(inDegree[i]==0){
                q.push(i);
                memo[i] = delay[i];    
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for (int i = 0; i < tree[now].size(); i++)
            {
                int next = tree[now][i];
                inDegree[next]--;
                memo[next] = max(memo[now]+delay[next],memo[next]);
                if(inDegree[next]==0)q.push(next);
            }
        }
        int W;
        cin >> W;
        cout<<memo[W]<<endl;
        
        
        
        
    }
}