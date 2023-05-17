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
const int MAX = 21;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 9999991;

vector<int> tree[MAX];
ll sz[MAX];
ll memo[MAX];
ll ncrTable[MAX][MAX];
ll nCr(int n, int r){
    if(r==1)return n;
    if(n==1)return 0;
    ll& now = ncrTable[n][r];
    if(now!=-1)return now;
    now = nCr(n-1,r)+nCr(n-1,r-1);
    return now;
}
ll dp(int cur){
    ll& sztmp = sz[cur];
    ll& memotmp = memo[cur];
    if(memotmp!=-1)return memotmp;
    sztmp = 1;
    memotmp = 1;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        dp(next);
    }
    if(tree[cur].size()==0){
    }
    else if(tree[cur].size()==1){
        sztmp+=sz[tree[cur][0]];
        memotmp=memo[tree[cur][0]];
    }
    else{
        sztmp+=sz[tree[cur][0]]+sz[tree[cur][1]] ;
        memotmp=memo[tree[cur][0]]*memo[tree[cur][1]]*nCr(sz[tree[cur][0]]+sz[tree[cur][1]],sz[tree[cur][0]]);
        memotmp%=MOD;
    }   
    

    return memotmp;
}
//sub 개수: dpsub1*dpsub2*sub1+sub2Csub1
int main()
{
    FAST int T;
    cin >> T;
    fill(&ncrTable[0][0], &ncrTable[MAX-1][MAX], -1);
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i <= 20; i++)
        {
            tree[i].clear();
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        int curPtr;
        for (int j = 1; j < n; j++)
        {
            curPtr = arr[0];
            while (true)
            {
                int larg = -1;
                int small = -1;
                for (int i = 0; i < tree[curPtr].size(); i++)
                {
                    if (tree[curPtr][i] > curPtr)
                    {
                        larg = tree[curPtr][i];
                    }
                    else
                    {
                        small = tree[curPtr][i];
                    }
                }
                if (arr[j] > curPtr)
                {
                    if(larg==-1){
                        tree[curPtr].push_back(arr[j]);
                        break;
                    }
                    else{
                        curPtr = larg;
                    }
                }
                else{
                    if(small==-1){
                        tree[curPtr].push_back(arr[j]);
                        break;
                    }
                    else{
                        curPtr = small;
                    }
                }
            }
        }
        
        fill(sz,sz+MAX,-1);
        fill(memo,memo+MAX,-1);
        cout<<dp(arr[0])<<endl;
    // for (int i = 0; i <= n; i++)
    //     {
    //         cout<<"sz: "<<sz[i]<<" memo: "<<memo[i]<<endl;
    //     }
    }
}
