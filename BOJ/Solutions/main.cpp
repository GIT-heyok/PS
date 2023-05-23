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
const int MAX = 4000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int main()
{
    FAST
    int n, m, l;
    cin >> n >> m >> l;
    int alphabets[l];
    for (int i = 0; i < l; i++)
    {
        alphabets[i] = 0;
    }
    vector<int> dr, dc;
    for (int i = -3; i <= 3; i++)
    {
        for (int j = -3; j <= 3; j++)
        {
            if(abs(i)+abs(j)<=4){
                dr.push_back(i);
                dc.push_back(j);
            }
        }
        
    }
    cout<<dr.size()<<endl;
    
    string order;
    cin >> order;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = temp[j]-'A';
            alphabet[arr[i][j]]++;
        }
        
    }
    ll path[l][l];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            path[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp[l];
            for (int k = 0; k < l; k++)
            {
                temp[k] = alphabets[k];
            }
            for (int k = 0; k < dr.size(); k++)
            {
                int nextr = i+dr[k];
                int nextc = j+dc[k];
                if(nextr>=0&&nextr<n&&nextc>=0&&nextc<m){
                    temp[arr[nextr][nextc]]--;
                }
            }
            for (int k = 0; k < l; k++)
            {
                path[arr[i][j]][k]+=temp[k];
            }   
        }
    }
    
    
    

} 