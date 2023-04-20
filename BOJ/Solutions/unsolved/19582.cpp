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

const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e7+3;


int main()
{
    FAST;
    int n;
    cin>>n;
    ll contests[n+1][2];
    for (int i = 0; i < n; i++)
    {
        cin >> contests[i][0] >> contests[i][1];
    }
    ll memo[n][2];
    memo[0][0] = contests[0][1];
    memo[0][1] = 0;
    for (int i = 1; i < n; i++)
    {  
        if(memo[i-1][0]>contests[i][0]){
            memo[i][0]=INF;
        }
        else{
            memo[i][0]=memo[i-1][0]+contests[i][1];
        }
        if(memo[i-1][1]>contests[i][0]){
            memo[i][1]=INF;
        }else{
            memo[i][1]=min(memo[i-1][0], memo[i-1][1]+contests[i][1]);
        }

    }
    for (int i = 0; i < n; i++)
    {
        cout<<memo[i][0]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < n; i++)
    {
        cout<<memo[i][1]<<" ";
    }
    cout<<endl;
    if(memo[n-1][1]<INF){
        cout<<"Kkeo-eok"<<endl;
    }
    else{
        cout<<"Zzz"<<endl;
    }
    
    
    
}