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

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e9;

int main(){
    FAST
    int n, m;
    cin >> n >> m;
    vector<int> shortcut[n+1][n+1];
    ll arr[n+1][n+1], dist[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j)dist[i][j]=0;
            else dist[i][j]=arr[i][j];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ll shorter = dist[i][k]+dist[k][j];
                if(dist[i][j]>shorter){
                    // cout<<"taking "<<i<<"->"<<k<<"->"<<j<<" instead"<<endl;
                    shortcut[i][j].clear();
                    for(int a: shortcut[i][k]){
                        shortcut[i][j].push_back(a);
                    }
                    shortcut[i][j].push_back(k);
                    for (int a: shortcut[k][j])
                    {
                        shortcut[i][j].push_back(a);
                    }
                    // cout<<"Path now for "<<i<<"->"<<j<<": "<<i<<"->";
                    // for (int a: shortcut[i][j])
                    // {
                    //     cout<<a<<"->";
                    // }
                    // cout<<j<<endl;
                    

                    
                    dist[i][j] = shorter;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dist[i][j]==INF)cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;

        
    }
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j){cout<<0<<endl;continue;}
            else if(dist[i][j]==INF){
                cout<<0<<endl;continue;
            }
            cout<<shortcut[i][j].size()+2<<" "<<i<<" ";
            for (int a: shortcut[i][j])
            {
                cout<<a<<" ";
            }
            cout<<j<<endl;   
        }

        
    }
    
    
    
    
    
}